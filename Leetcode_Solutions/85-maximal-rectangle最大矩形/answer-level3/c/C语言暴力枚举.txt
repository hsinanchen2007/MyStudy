```
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static char **gMatrix;
static int m, n;

int GetSize(int row, int col)
{
	int i, j;
	int ans = 0;
	int nTmp = n, mTmp = m;
	int a, b;

	for (i = row; i < mTmp; i++) {
		/* 如果这一行的第一个是0， 则下边的行不需要遍历了 */
		if (gMatrix[i][col] == '0') {
			mTmp = i;
			continue;
		}

		for (j = col; j < nTmp; j++) {
			/* 如果这一行出现一个0，则后边的列也不需要遍历了 */
			if (gMatrix[i][j] == '0') {
				nTmp = j;
				continue;
			}
		}

		a = i + 1 - row;
		b = nTmp - col;

		ans = MAX(ans, a * b);
	}

	return ans;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
	int i, j;
	int ans = 0;

	if (matrixSize == 0 || matrix == NULL || *matrix == NULL || matrixColSize == NULL) {
		return 0;
	}

	gMatrix = matrix;
	m = matrixSize;
	n = matrixColSize[0];

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (gMatrix[i][j] == '1') {
				ans = MAX(GetSize(i, j), ans);
			}
		}
	}

	return ans;
}
```
