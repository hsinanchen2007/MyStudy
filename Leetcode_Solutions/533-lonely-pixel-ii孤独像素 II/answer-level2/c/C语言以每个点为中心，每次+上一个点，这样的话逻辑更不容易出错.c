### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 201

static int same[MAX_NODE][MAX_NODE];
static int row_black[MAX_NODE];
static int col_black[MAX_NODE];

int findBlackPixel(char **picture, int pictureSize, int *pictureColSize, int N)
{
	int row;
	int col;
	int nrow;
	int black_num;
	int cur_row;
	int cur_col;
	int tmp_num;
	int in_row;
	int in_col;

	int ans = 0;
	if (!picture || !pictureSize)
		return 0;

	memset(same, 0, sizeof(same));
	memset(row_black, 0, sizeof(row_black));
	memset(col_black, 0, sizeof(row_black));
	for (row = 0; row < pictureSize; row++) {
		black_num = 0;
		for (col = 0; col < *pictureColSize; col++) {
			if (picture[row][col] == 'B')
				black_num++;
		}
		same[row][row] = 1;
		row_black[row] = black_num;
		for (nrow = row + 1; nrow < pictureSize; nrow++) {
			if (!memcmp(picture[row], picture[nrow],
				    *pictureColSize)) {
				same[row][nrow] = 1;
				same[nrow][row] = 1;
			}
		}
	}
	for (col = 0; col < *pictureColSize; col++) {
		black_num = 0;
		for (row = 0; row < pictureSize; row++) {
			if (picture[row][col] == 'B')
				black_num++;
		}
		col_black[col] = black_num;
	}
	for (cur_col = 0; cur_col < *pictureColSize; cur_col++) {
		for (cur_row = 0; cur_row < pictureSize; cur_row++) {
			if (row_black[cur_row] == N && col_black[cur_col] == row_black[cur_row] && picture[cur_row][cur_col] == 'B') {
				tmp_num = 0;
				/* now cur_col is N cur_row is N */
				for (row = 0; row < pictureSize; row++) {
					if (picture[row][cur_col] == 'B') {
						if (same[row][cur_row] != 1) {
							break;
						}
					}
				}
				if (row == pictureSize) {
					ans += 1;
				}
			}
		}
	}
	return ans;
}
```