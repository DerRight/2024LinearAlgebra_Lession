#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double gaussJordanDeterminant(vector<vector<double>>& A, int n) {
	double det = 1; // �ΨӦs���C����

	// �M��D�n���氵������n���h�k
	for (int i = 0; i < n; i++) {
		double maxEl = fabs(A[i][i]); // maxEl �ΨӦs�̤j��
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(A[k][i]) > maxEl) {
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}

		// �N�̤j�����ثe����洫
		if (maxRow != i) {
			swap(A[maxRow], A[i]);
			det = -det;
		}

		// �p�G�פ観0���ܡA�N�^��0
		if (A[i][i] == 0) {
			return 0;
		}

		// �B�z�e�ɳ��H�~����L��
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
	vector<vector<double>> A(n,	vector<double>(n)); // ��l�ƤG���}�C��n��Bm�C

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	double det = gaussJordanDeterminant(A, n);

	cout << "��C���Ȭ��G" << det << endl;

	return 0;
}