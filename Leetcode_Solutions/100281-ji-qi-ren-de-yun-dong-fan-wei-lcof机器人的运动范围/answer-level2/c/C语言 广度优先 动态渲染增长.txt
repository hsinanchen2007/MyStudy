### 解题思路
广度优先，动态增长

### 代码

```c
int movingCount(int m, int n, int k){
    int res = 1;
	int** temp = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		temp[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
		}
	}
	temp[0][0] = 1;
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if ((temp[i][j] == 0) && ((i > 0 && temp[i - 1][j] == 1) ||
										  (i < m - 1 && temp[i + 1][j] == 1) ||
										  (j > 0 && temp[i][j - 1] == 1) ||
										  (j < n - 1 && temp[i][j + 1] == 1))) {
					int temp_k = i / 10 + i % 10 + j / 10 + j % 10;
					if (temp_k <= k) {
						temp[i][j] = 1;
						flag = 1;
						res++;
					}
				}
			}
		}
	} while (flag);
		
	for (int i = 0; i < m; i++) {
		free(temp[i]);
	}
	free(temp);
	return res;
}
```