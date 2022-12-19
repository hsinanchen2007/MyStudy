### 解题思路
1. 扫描所有方程组，把所有的符号都放入一个数组 symbols。对symbols数组使用qsort进行排序。
1. 以每个符号的数组下标作为节点号，建立并查集合
- parent[i] 表示 i 节点 的 父节点
- value[i] == (symbols[parent[i]] / symbols[i])
- 从节点 i 到 其根节点上的 value值的连续乘积就表示 根节点 与 i节点的比值。
- 计算 i节点 和 j节点 的比值，分别计算共同根节点和i, j 俩节点的比值，然后相除就可

在查找根节点时，不可以使用路径压缩。

### 代码

```c
int find(int *parent, int n)
{
	/* Do not compress the path!!! */
	while (parent[n] != n)
		n = parent[n];
	return n;
}

void merge(int *parent, double *value, int x, int y, double val)
{
	int parent_x = find(parent, x);
	int parent_y = find(parent, y);

	if (parent_x == parent_y)
		return;
	parent[parent_y] = parent_x;
	value[parent_y] = (value[x]/value[y]) * val;
}

/* 计算 集合根节点 和 n节点 的比值 */
double get_value(int *parent, double *value, int n)
{
	double v = 1.0;
	while (parent[n] != n) {
		v *= value[n];
		n = parent[n];
	}

	v *= value[n];
	return v;
}

/* 快速排序 和 二分查找 的比较函数 */
int compare(const void *p1, const void *p2)
{
	return strcmp(*(char * const *)p1, *(char * const *)p2);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char *** equations, int equationsSize, int* equationsColSize,
					 double* values, int valuesSize, char *** queries,
					 int queriesSize, int* queriesColSize, int* returnSize){
	int max_symbols = equationsSize * 2;
	int count = 0;
	int i, j;
	char **symbols = (char **) calloc(max_symbols, sizeof(char *));
	char **search_ret, *key;
	int *parent;
	double *value;
	int m[2] = {0, 0};
	double *ans, v1, v2;

	*returnSize = queriesSize;
	ans = (double *) calloc(queriesSize, sizeof(double));
	for (i = 0; i < queriesSize; i++)
		ans[i] = -1.0;

	for (i = 0; i < equationsSize; i++) {
		for (j = 0; j < 2; j++) {
			key = strdup(equations[i][j]);
			search_ret = (char **)bsearch(&key, symbols, count, sizeof(char **), compare);
			if (search_ret == NULL) {
				symbols[count++] = equations[i][j];
				qsort(symbols, count, sizeof(char *), compare);
			}
			free(key);
		}
	}

	parent = (int *) calloc(count, sizeof(int));
	value = (double *) calloc(count, sizeof(double));
	for (i = 0; i < count; i++) {
		parent[i] = i;
		value[i] = 1.0;
	}

	for (i = 0; i < equationsSize; i++) {
		for (j = 0; j < 2; j++) {
			key = strdup(equations[i][j]);
			search_ret = (char **)bsearch(&key, symbols, count, sizeof(char **), compare);
			m[j] = search_ret - symbols;
			free(key);
		}
		merge(parent, value, m[0], m[1], values[i]);
	}

	for (i = 0; i < queriesSize; i++) {
		for (j = 0; j < 2; j++) {
			key = strdup(queries[i][j]);
			search_ret = (char **)bsearch(&key, symbols, count, sizeof(char **), compare);
			free(key);
			if (search_ret == NULL)
				goto out;
			else
				m[j] = search_ret - symbols;
		}
		if (find(parent, m[0]) != find(parent, m[1]))
			goto out;
		v1 = get_value(parent, value, m[0]);
		v2 = get_value(parent, value, m[1]);
		ans[i] = v2 / v1;
out:
		;
	}

	free(symbols);
	free(value);
	free(parent);
	return ans;
}
```