中间6个数字只有64种排列组合，对应数字0~63，共形成6个循环组，定义为全局变量。遍历找到cell所在循环组，根据总次数找到循环终止位置，将数字还原为int *。
```
char groups[6][14] = {{0, 63, 30, 12, 33, 45, 51},
					  {1, 61, 27, 4, 53, 15, 38, 32, 47, 54, 8, 43, 60, 25},
					  {2, 58, 22, 24, 3, 56, 19, 16, 23, 26, 6, 48, 7, 50},
					  {5, 55, 10, 46, 52, 13, 35, 40, 59, 20, 29, 11, 44, 49},
					  {9, 41, 57, 17, 21, 31, 14, 36, 37, 39, 34, 42, 62, 28},
					  {18}};
char groupsnums[6] = {7, 14, 14, 14, 14, 1};

int *prisonAfterNDays(int *cells, int cellsSize, int N, int *returnSize)
{
	*returnSize = cellsSize;
	int *rc = (int *)malloc(cellsSize * sizeof(int));
	if (N == 0) {
		memcpy(rc, cells, cellsSize * sizeof(int));
		return rc;
	}

	int ab[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	for (int j = 1; j < 7; j++) {
		ab[j] = (cells[j - 1] == cells[j + 1]) ? 1 : 0;
	}
	if (N == 1) {
		memcpy(rc, ab, cellsSize * sizeof(int));
		return rc;
	}

	char num = ab[1] * 32 + ab[2] * 16 + ab[3] * 8 + ab[4] * 4 + ab[5] * 2 + ab[6];

	int rtnum = -1;
	for (int i = 0; i < 6; i++) {
		bool bfind = false;
		int j = 0;
		for (; j < groupsnums[i]; j++) {
			if (num == groups[i][j]) {
				bfind = true;
				break;
			}
		}

		if (bfind) {
			if (i == 5) {
				rtnum = groups[5][0];
			} else {
				rtnum = groups[i][(j + N - 1) % groupsnums[i]];
			}
			break;
		}
	}

	memset(rc, 0, cellsSize * sizeof(int));
	for (int i = 6; i > 0; i--) {
		rc[i] = rtnum % 2;
		rtnum = rtnum / 2;
	}

	return rc;
}
```

