### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
	int i = 0, j = 0, m, n, k = 0, p = 0, cnt = 0; char a, b;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] == 'R')
			{
				m = i; n = j; break;
			}
		}
	i = m + 1; j = m - 1; k = n + 1; p = n - 1;
		while (i <= 8 || j >= -1 || k <= 8 || p >= -1)
		{
			if (i > 7)i--;
			else
			{
				if (board[i][n] == 'B')i = 7;
				else
					if (board[i][n] == 'p') {cnt++;i=7;}
			}i++;
			if (j < 0)j++;
			else {
				if (board[j][n] == 'B')j = 0;
				else
					if (board[j][n] == 'p') {cnt++;j=0;}
			}j--;
			if (k > 7)k--;
			else {
				if (board[m][k] == 'B')k = 7;
				else
					if (board[m][k] == 'p')  {cnt++;k=7;}
			}k++;
			if (p < 0)p++;
			else {
				if (board[m][p] == 'B')p = 0;
				else
					if (board[m][p] == 'p') {cnt++;p=0;}
			}p--;
        if(i==8&&j==-1&&k==8&&p==-1)
        break;
		}
	return cnt;
}
```