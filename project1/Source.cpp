#include <iostream>
#include <vector>

using namespace std;

// ����-��n���h�k�A�P�ɭp��ϯx�}
bool gaussianJordanElimination(vector<vector<double>>& mat, vector<vector<double>>& inverse) {
    int n = mat.size();

    // �c�y�W�s�x�}
    vector<vector<double>> augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = mat[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0; // ���x�}
        }
    }

    // �N�W�s�x�}�ഫ���W�s�x�}���k�b��������l�x�}���ϯx�}
    for (int i = 0; i < n; ++i) {
        // �N��i�C����i�Ӥ����]�m��1
        double divisor = augmented[i][i];
        if (divisor == 0)
            return false; // �L�k�p��ϯx�}�A��^false
        for (int j = i; j < 2 * n; ++j)
            augmented[i][j] /= divisor;

        // �ϥβ�i��Ӯ��h��L�檺��i�C����
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = i; j < 2 * n; ++j)
                    augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    // �����ϯx�}
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return true; // ���\�p��ϯx�}�A��^true
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
        cout << "�ϯx�}���s�b!" << endl;
    }

    return 0;
}
