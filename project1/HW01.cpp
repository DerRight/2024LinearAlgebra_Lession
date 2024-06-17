#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void gaussJordan(vector<vector<double>>& A, int n, int m) {
	// 尋找主要元
	for (int i = 0; i < n; i++) {
		double maxEl = fabs(A[i][i]); // maxEl 用來存最大值
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(A[k][i]) > maxEl) {
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}

		// 換行
		for (int k = 0; k < m; k++) {
			swap(A[maxRow][k], A[i][k]);
		}

		// 處理前導壹
		double one = A[i][i];
		if (one != 0) {
			for (int k = 0; k < m; k++) {
				A[i][k] /= one;
			}
		}

		// 處理前導壹以外的其他數
		for (int k = 0; k < n; k++) {
			if (k != i) {
				double coeff = A[k][i];
				for (int j = 0; j < m; j++) {
					A[k][j] -= coeff * A[i][j];
				}
			}
		}
	}
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m; // n行、m列
	vector<vector<double>> A(n,	vector<double>(m)); // 初始化二維陣列為n行、m列

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	
	gaussJordan(A, n, m);

	cout << fixed << setprecision(2);
	cout << "簡化列梯形為：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}