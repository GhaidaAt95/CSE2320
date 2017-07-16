#include <iostream>
using namespace std;

/*int s[23] = { 0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484 }; //s [n+1]  n=22
int n = 22;
int c[1266];
int m = 1265;
int answer[3][22] = { 0 };
int index[23] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 };*/
/*int s[8] = { 0,1,2,3,4,4,5,8 }; // s[n+1]=s[8] n=7
int n = 7;
int m = 9;
int c[10][10];
int a[3][7];*/
/*int s[23] = { 0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484 };
int n = 22;
int m = 1265;
int c[1266][1266];
int a[3][22];*/
/*int s[7] = { 0,3,3,3,3,3,3 };
int n = 6;
int m = 6;
int c[7][7];*/
int s[7] = { 0,3,3,5,5,6,8 };
int n = 6;
int m = 10;
int c[11][11];
int a[3][6];
/*int s[7] = { 0,3,6,9,12,15,18 };
int n = 6;
int m = 21;
int c[22][22];*/
/*int s[9] = { 0,1,1,3,6,9,1,18,3 };
int n = 8;
int m = 14;
int c[15][15];*/
/*int s[10] = { 0,1,1,1,1,1,1,1,1,1};
int n = 9;
int m = 3;
int c[10][10];
int a[3][9] = { 0 };*/
/*
int s[36] = { 0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225 };
int n = 35;
int m = 4970;
int c[4971];
int answer[3][36];
int index[36];
int z = 2;*/

void subsetSum()
{
	int i = 0, j = 0,k=1;
	int left;
	for (i = 0; i < m + 1; i++) {
		if (i == 0) j = 1;
		else j = i;
		for (; j < m + 1; j++) {
			for (k = 1; k <= n; k++) {
				left = j - s[k];
				if (left >= 0 && c[i][left] < k) {
					break;
				}
			}//K_loop
			c[i][j] = k;
			c[j][i] = k;
		}//J_loop	
	}//I_lopp
	if (c[m][m] == n + 1) {
		cout << " No Solution \n";
     }
	else {
		i = m; j = m;
		a[0][c[i][j]] = s[c[i][j]];
		j = j - s[c[i][j]];
		while (i != 0 || j != 0) {
			if (i > j) {
				a[2][c[i][j]] = s[c[i][j]];
				i -= s[c[i][j]];
				}
			else {
				a[0][c[i][j]] = s[c[i][j]];
				j -= s[c[i][j]];
			}
		}
		for (i = 1; i <= n; i++) {
			if (a[0][i] == 0 && a[2][i] == 0)
				a[1][i] = s[i];
		}
	}
	
}
int main() { 
	c[0][0] = 0;
	subsetSum();
	int sum1 = 0, sum2 = 0, sum3 = 0;

	for (int i = 0; i < m + 1; i++) {
		cout << i << "   ";
		for (int j = 0; j < m + 1; j++) {
			cout <<"  "<<c[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n\n**************************************\n";
	for (int g = 1; g <=n; g++) {
		cout << g << "    " << a[0][g] << "    " << a[1][g] << "    " << a[2][g] << endl;
		sum1 += a[2][g];
		sum2 += a[1][g];
		sum3 += a[0][g];
	}
	cout << " sum1 = " << sum1 << endl;
	cout << " sum2 = " << sum2 << endl;
	cout << " sum3 = " << sum3 << endl;
	system("pause");
	return 0;
}

/*
int s2[8] = {0,1,2,3,4,4,5,8}; // s[n+1]=s[8] n=7
int n2 = 7;
int m2 = 9;
*/
/*
    0  1  2  3  4  5  6  7  8  9
0   0  1  2  2  3  3  3  4  4  4
1   1  8  8  8  8  8  8  8  8  8
2   2  8  8  8  8  8  8  8  8  8
3   2  8  8  3  8  8  8  8  8  8
4   3  8  8  8  4  4  4  5  5  5
5   3  8  8  8  4  6  6  6  6  6
6   3  8  8  8  4  6  8  8  8  8
7   4  8  8  8  5  6  8  8  8  8
8   4  8  8  8  5  6  8  8  7  7
9   4  8  8  8  5  6  8  8  7  6
*/
/*
   0  1  2  3  4  5  6
0  0  7  7  1  7  7  2
1  7  7  7  7  7  7  7
2  7  7  7  7  7  7  7
3  1  7  7  2  7  7  3
4  7  7  7  7  7  7  7
5  7  7  7  7  7  7  7
6  2  7  7  3  7  7  4
*/

/*
 i
 |
\ / 
    0  1  2  3  4  5  6  7  8  9  <-- j
0   0  1  2  2  3  3  3  4  4  4
1   1  8  2  3  4  3  4  4  5  4
2   2  2  8  3  3  4  6  4  4  5
3   2  3  3  3  4  4  4  4  5  5
4   3  4  3  4  4  5  4  5  5  6
5   3  3  4  4  5  4  5  5  6  5
6   3  4  6  4  4  5  6  5  5  6
7   4  4  4  4  5  5  5  5  6  6
8   4  5  4  5  5  6  5  6  6  6
9   4  4  5  5  6  5  6  6  6  7
*/

/*
int s[7] = { 0,3,3,3,3,3,3 };

    0  1  2  3  4  5  6
0   0  7  7  1  7  7  2
1   7  7  7  7  7  7  7
2   7  7  7  7  7  7  7
3   1  7  7  2  7  7  3
4   7  7  7  7  7  7  7
5   7  7  7  7  7  7  7
6   2  7  7  3  7  7  4
*/

/*
   int s[7] = { 0,3,6,9,12,15,18 };
        0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21
   0    0  7  7  1  7  7  2  7  7  2  7  7  3  7  7  3  7  7  3  7  7  4
   1    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   2    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   3    1  7  7  7  7  7  2  7  7  3  7  7  4  7  7  3  7  7  4  7  7  4
   4    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   5    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   6    2  7  7  2  7  7  7  7  7  3  7  7  3  7  7  4  7  7  5  7  7  4
   7    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   8    7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   9    2  7  7  3  7  7  3  7  7  3  7  7  4  7  7  4  7  7  4  7  7  4
   10   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   11   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   12   3  7  7  4  7  7  3  7  7  4  7  7  4  7  7  5  7  7  4  7  7  5
   13   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   14   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   15   3  7  7  3  7  7  4  7  7  4  7  7  5  7  7  4  7  7  5  7  7  5
   16   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   17   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   18   3  7  7  4  7  7  5  7  7  4  7  7  4  7  7  5  7  7  5  7  7  6
   19   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   20   7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7  7
   21   4  7  7  4  7  7  4  7  7  4  7  7  5  7  7  5  7  7  6  7  7  5

*/

/*
int s[10] = { 0,1,1,1,1,1,1,1,1,1};
0     0    1    2    3
1     1    2    3    4
2     2    3    4    5
3     3    4    5    6
*/
/*

j = m; i = m;
a[0][c[i][j]] = s[c[i][j]];
j = j - s[c[i][j]];
for (; i > 0; i -= s[c[i][j]]) {
a[2][c[i][j]] = s[c[i][j]];
}
for (; j > 0; j -= s[c[i][j]]) {
a[0][c[i][j]] = s[c[i][j]];
}
for (i = 1; i <= n; i++) {
if (a[0][i] == 0 && a[2][i] == 0)
a[1][i] = s[i];
}
*/