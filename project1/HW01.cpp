#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void gaussJordan(vector<vector<double>>& A, int n, int m) {
	// �M��D�n��
	for (int i = 0; i < n; i++) {
		double maxEl = fabs(A[i][i]); // maxEl �ΨӦs�̤j��
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(A[k][i]) > maxEl) {
				maxEl = fabs(A[k][i]);
				maxRow = k;
			}
		}

		// ����
		for (int k = 0; k < m; k++) {
			swap(A[maxRow][k], A[i][k]);
		}

		// �B�z�e�ɳ�
		double one = A[i][i];
		if (one != 0) {
			for (int k = 0; k < m; k++) {
				A[i][k] /= one;
			}
		}

		// �B�z�e�ɳ��H�~����L��
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
	cin >> n >> m; // n��Bm�C
	vector<vector<double>> A(n,	vector<double>(m)); // ��l�ƤG���}�C��n��Bm�C

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	
	gaussJordan(A, n, m);

	cout << fixed << setprecision(2);
	cout << "²�ƦC��ά��G" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}