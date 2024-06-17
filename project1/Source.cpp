#include <iostream>
#include <vector>

using namespace std;

// 高斯-喬登消去法，同時計算反矩陣
bool gaussianJordanElimination(vector<vector<double>>& mat, vector<vector<double>>& inverse) {
    int n = mat.size();

    // 構造增廣矩陣
    vector<vector<double>> augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = mat[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0; // 單位矩陣
        }
    }

    // 將增廣矩陣轉換為增廣矩陣的右半部分為原始矩陣的反矩陣
    for (int i = 0; i < n; ++i) {
        // 將第i列的第i個元素設置為1
        double divisor = augmented[i][i];
        if (divisor == 0)
            return false; // 無法計算反矩陣，返回false
        for (int j = i; j < 2 * n; ++j)
            augmented[i][j] /= divisor;

        // 使用第i行來消去其他行的第i列元素
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = i; j < 2 * n; ++j)
                    augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    // 提取反矩陣
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return true; // 成功計算反矩陣，返回true
}

int main() {
    int n;
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    vector<vector<double>> inverse(n, vector<double>(n));

    if (gaussianJordanElimination(mat, inverse)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << inverse[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "反矩陣不存在!" << endl;
    }

    return 0;
}
