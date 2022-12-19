### 解题思路
两种思路，三种做法
1. 暴力枚举，通过开大数组，实现hash O(1)查找
2. 二分法
	- 调用库函数bsearch，实现二分查找
	- 自己实现二分查找函数

### 代码

【暴力枚举】
```
#define MAX_N 10001
#define MAX_M 500

char hash[MAX_M][MAX_N] = { 0 };

int smallestCommonElement(int** mat, int matSize, int* matColSize){
    int i, j, k;
    int tar, flag;
    for (i = 0; i < MAX_M; i++) {
        for (j = 0; j < MAX_N; j++) {
            hash[i][j] = 0;
        }
    }

    for (i = 0; i < matSize; i++) {
        for (j = 0; j < *matColSize; j++) {
            tar = mat[i][j];
            hash[i][tar] = 1;
        }
    }    

    for (k = 0; k < *matColSize; k++) {
        tar = mat[0][k];
        flag = 1;
        for (i = 1; i < matSize; i++) {
            if (hash[i][tar] == 0) {
                flag = 0;
                break;
            }
        }  
        if (flag == 1) {
            return tar;
        }
    }
    return -1;
}
```

【调用库函数bsearch】

```
#include <stdio.h>
static int Comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int smallestCommonElement(int** mat, int matSize, int* matColSize)
{
	int i, j, k;
	int tar;
	bool flag, ret;

	for (k = 0; k < *matColSize; k++) {
		tar = mat[0][k];
		flag = true;
		for (i = 1; i < matSize; i++) {
			ret = bsearch(&tar, mat[i], *matColSize, sizeof(int), Comp);
			if (!ret) {
				flag = false;
				break;
			}
		} 
		if (flag == true) {
			return tar;
		}
	}
	return -1;
}


```

【自己实现二分查找】
```c
static bool Bsearch(int *nums, int len, int tar)
{
	int begin, end, mid;
	begin = 0;
	end = len;
	while (end - begin > 1) {
		mid = begin + (end - begin) / 2;
		if (nums[mid] <= tar) {
			begin = mid;
		} else {
			end = mid;
		}
	}
	return tar == nums[begin];
}

int smallestCommonElement(int** mat, int matSize, int* matColSize)
{
	int i, j, k;
	int tar;
	bool flag, ret;

	for (k = 0; k < *matColSize; k++) {
		tar = mat[0][k];
		flag = true;
		for (i = 1; i < matSize; i++) {
			ret = Bsearch(mat[i], *matColSize, tar);
			if (!ret) {
				flag = false;
				break;
			}
		} 
		if (flag == true) {
			return tar;
		}
	}
	return -1;
}


```