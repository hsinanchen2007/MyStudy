### 解题思路
直接扔到hash桶里边，先达到size的直接返回，因为已经排序

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 100000

static int hash[MAX_NODE];

int smallestCommonElement(int** mat, int matSize, int* matColSize){
	int row;
	int col;
	if (!mat || matSize == 0) {
		return -1;
	}
	memset(hash, 0, sizeof(hash));
	for (row = 0; row < matSize; row++) {
		for (col = 0; col < *matColSize; col++) {
			hash[mat[row][col]]++;
			if (row == matSize - 1) {
				if (hash[mat[row][col]] == matSize) {
					return mat[row][col];
				}
			}
		}
	}
	return -1;
}
```