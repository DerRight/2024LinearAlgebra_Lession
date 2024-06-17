#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double gaussJordanDeterminant(vector<vector<double>>& A, int n) {
	double det = 1; // 用來存放行列式值

	// 尋找主要的行做高斯喬登消去法
	for (int i = 0; i < n; i++) {
		double maxEl = fabs(A[i][i]); // maxEl 用來存最大值
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(A[k][i]) > maxEl) {
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}

		// 將最大的行跟目前的行交換
		if (maxRow != i) {
			swap(A[maxRow], A[i]);
			det = -det;
		}

		// 如果斜方有0的話，就回傳0
		if (A[i][i] == 0) {
			return 0;
		}

		// 處理前導壹以外的其他數
		for (int k = i + 1; k < n; k++) {
			double factor = A[k][i] / A[i][i];
			for (int j = i; j < n; j++) {
				A[k][j] -= factor * A[i][j];
			}
		}
		det *= A[i][i];
	}
	return det;
}

int main() {
	int n = 0;
	cin >> n;
	vector<vector<double>> A(n,	vector<double>(n)); // 初始化二維陣列為n行、m列

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	double det = gaussJordanDeterminant(A, n);

	cout << "行列式值為：" << det << endl;

	return 0;
}