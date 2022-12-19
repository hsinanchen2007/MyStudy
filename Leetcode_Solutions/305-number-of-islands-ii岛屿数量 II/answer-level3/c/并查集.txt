### 解题思路
Find的时候自带路径压缩，不需要通过rank来进行合并也可以

### 代码

```c
#include <stdio.h>
#define DIRECT 4
static int g_m, g_n, g_ans;
static int **g_matrix;
static int *g_father;
static int g_iGo[] = {-1, 0, 1, 0};
static int g_jGo[] = {0, 1, 0, -1};

static int FindFather(int n)
{
	if (g_father[n] == n) {
		return n;
	}

	return g_father[n] = FindFather(g_father[n]);
}

static void SetUnion(int a, int b)
{
	int aFather, bFather;
	aFather = FindFather(a);
	bFather = FindFather(b);

	/* 找小的当爹 */
	if (aFather < bFather) {
		g_father[bFather] = aFather;
	} else if (bFather < aFather) {
		g_father[aFather] = bFather;
	}
}

static bool IsValid(int i, int j)
{
	if (i < 0 || i >= g_m ||
		j < 0 || j >= g_n) {
		return false;
	}
	return true;
}

int* numIslands2(int m, int n, int** positions, int positionsSize, 
				 int* positionsColSize, int* returnSize){
	int i, j, k, pos, tarI, tarJ, nextI, nextJ, a, b, aFather, bFather;
	int *ans = (int *)calloc(1, sizeof(int) * positionsSize);

	g_m = m;
	g_n = n;
	g_ans = 0;
	g_father = (int *)calloc(1, sizeof(int) * g_m * g_n);
	g_matrix = (int **)calloc(1, sizeof(int *) * g_m);
	for (i = 0; i < g_m; i++) {
		g_matrix[i] = (int *)calloc(1, sizeof(int) * g_n);
	}

	for (i = 0; i < g_m * g_n; i++) {
		g_father[i] = i;
	}

	for (pos = 0; pos < positionsSize; pos++) {
		tarI = positions[pos][0];
		tarJ = positions[pos][1];
		if (g_matrix[tarI][tarJ] == 1) {
			ans[pos] = g_ans;
			continue;
		}
		g_matrix[tarI][tarJ] = 1;
		g_ans++;
		ans[pos] = g_ans;
		for (k = 0; k < DIRECT; k++) {
			nextI = tarI + g_iGo[k];
			nextJ = tarJ + g_jGo[k];
			if (!IsValid(nextI, nextJ)) {
				continue;
			}
			if (g_matrix[nextI][nextJ] == 0) {
				continue;
			}
			a = tarI * g_n + tarJ;
			aFather = FindFather(a);
			b = nextI * g_n + nextJ;
			bFather = FindFather(b);
			if (aFather != bFather) {
				SetUnion(a, b);
				ans[pos]--;
				g_ans--;
			}
		}
	}
	*returnSize = positionsSize;
	return ans;
}
```