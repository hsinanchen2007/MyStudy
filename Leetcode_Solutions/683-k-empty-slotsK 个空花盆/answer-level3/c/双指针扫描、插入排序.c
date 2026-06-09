### 解题思路
1、每天左右扫描找到符合条件的（176 ms）
2、模拟插入排序（988 ms），数据的挪动效率低，慎用

### 代码
【双指针扫描】
```
#include <stdio.h>
#define MAX_LEN 20001
static bool *flag;

static bool IsOk(int K, int n, int bulbsSize)
{   
	int left = n - 1;
	int right = n + 1;
	int openFlag = 0;
	int tmp = 0;
	while (left > 0) {
		if (flag[left] == true) {
			openFlag = 1;
			break;
		}
		tmp++;
		left--;
	}
	if (tmp == K && openFlag == 1) {
		return true;
	}
	tmp = 0;
	openFlag = 0;
	while (right <= bulbsSize) {
		if (flag[right] == true) {
			openFlag = 1;
			break;
		}
		tmp++;
		right++;
	}    
	if (tmp == K && openFlag == 1) {
		return true;
	}
	return false;    
}

int kEmptySlots(int* bulbs, int bulbsSize, int K)
{
	int i;
	int ans = -1;
	flag = (bool *)calloc(1, sizeof(bool) * MAX_LEN);

	flag[bulbs[0]] = true;

	/* 每次开一朵花，则前后遍历，看是否满足条件，从第二朵花开始 */
	for (i = 1; i < bulbsSize; i++) {
		flag[bulbs[i]] = true;
		if (IsOk(K, bulbs[i], bulbsSize)) {
			ans = i + 1;
			break;
		}
	}
	free(flag);
	return ans;
}
```

【插入排序】
```c
#define MAX_LEN 20001

static int *g_arr;
static int g_arrIndex;

static int LowerBound(int *arr, int len, int tar)
{
    int left, right, mid;

    left = 0;
    right = len;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] >= tar) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

static bool InsertNum(int n, int k)
{
    int preIndex, postIndex;
    int index = LowerBound(g_arr, g_arrIndex, n);

    memmove(g_arr + index + 1, g_arr + index, sizeof(int) * (g_arrIndex - index));
    g_arr[index] = n;
    g_arrIndex++;
    preIndex = index - 1;
    if (preIndex >= 0) {
        if (n - g_arr[preIndex] == k + 1) {
            return true;
        }
    }
    postIndex = index + 1;
    if (postIndex != g_arrIndex) {
        if (g_arr[postIndex] - n == k + 1) {
            return true;
        }
    }
    return false;
}

int kEmptySlots(int* bulbs, int bulbsSize, int k)
{
    int i;
    g_arr = (int *)calloc(1, sizeof(int) * MAX_LEN);
    g_arrIndex = 0;
    for (i = 0; i < bulbsSize; i++) {
        if (InsertNum(bulbs[i], k)) {
            return i + 1;
        }
    }
    return -1;
}

```