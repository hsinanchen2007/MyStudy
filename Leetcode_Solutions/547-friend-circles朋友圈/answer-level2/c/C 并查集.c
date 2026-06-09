```
#include <stdio.h>

#define MAX_N 201

int father[MAX_N] = { 0 };

int FindFather(int n)
{
	while (father[n] != n) {
		n = father[n];
	}

	return n;
}

void SetUnion(int a, int b)
{
	int aFather, bFather;

	aFather = FindFather(a);
	bFather = FindFather(b);

	if (aFather != bFather) {
		father[aFather] = bFather;
	}
}

int GerFathers(int MSize)
{
	int i;
	int ans = 0;

	for (i = 0; i < MSize; i++) {
		if (father[i] == i) {
			ans++;
		}
	}

	return ans;
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
	int i, j;

	/* 初始化并查集 */
	for (i = 0; i < MSize; i++) {
		father[i] = i;
	}

	for (i = 0; i < MSize; i++) {
		for (j = 0; j < i; j++) {
			if (M[i][j] == 1) {
				SetUnion(i, j);
			}
		}
	}

	return GerFathers(MSize);
}

```
