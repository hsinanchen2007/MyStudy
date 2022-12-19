### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdlib.h>
int roww[1000] = { 0 };
int coll[1000] = { 0 };
bool dfs(char** pic, int row, int col, int i, int j) {
	for (int k = 0; k < row; k++) {
		if (pic[k][j] == 'B' && k!= i) {
			coll[k] = 1;
			return false;
		}
	}
	for (int k = 0; k < col; k++) {
		if (pic[i][k] == 'B' && k!=j) {
			roww[k] = 1;
			return false;
		}
	}
	return true;
}
int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize) {
	int m = pictureSize;
	int n = *pictureColSize;
	for (int i = 0; i < 1000; i++) {
		roww[i] = 0;
		coll[i] = 0;
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
        if(coll[i]==1)//注释掉此处，效率只有7%
        continue;
		for (int j = 0; j < n; j++) {
            //printf("%c ",picture[i][j]);
			if (picture[i][j] == 'B'&&roww[j]==0&&coll[i]==0 ) {
				if (dfs(picture, m, n, i, j)) {
					count++;
				}				
			}
		}
	}
	return count;
}
```