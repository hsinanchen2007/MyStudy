### 解题思路
每次找到最大的index
从开头到最大的index反转
然后整体反转，这将最大的归位
如果找到的最大的index就是归位的位置，则直接continue
如果找到的最大的index为0，可以少一次反转。

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
每次最大的放到最后一个，放到最后一个分成2步，第一步找到所在的index
然后翻转index，此时数字被反转到第一个，然后反转全部，则归位到最后一个
*/

static int ans[4096 * 4];

int find_max_index(int *data, int size)
{
	int ret;
	int max = INT_MIN;
	int loop;

	if (size <= 0)
		return 0;
	for (loop = 0; loop < size; loop++) {
		if (data[loop] > max) {
			ret = loop;
			max = data[loop];
		}
	}
	return ret;
}

void swap_data(int *data, int start, int end)
{
	int tmp;
	if (start >= end)
		return;
	tmp = data[start];
	data[start] = data[end];
	data[end] = tmp;
	swap_data(data, start + 1, end - 1);
	return;
}

int *pancakeSort(int *A, int ASize, int *returnSize)
{
	int loop;
	int index;
	int ans_size = 0;

	if (!A || ASize == 0 || ASize == 1) {
		*returnSize = 0;
		return ans;
	}
	for (loop = ASize - 1; loop >= 0; loop--) {
		index = find_max_index(A, loop + 1);
		if (index == loop)
			continue;
		if (index != 0) {
			ans[ans_size++] = index + 1;
			swap_data(A, 0, index);
		}
		ans[ans_size++] = loop + 1;
		swap_data(A, 0, loop);
	}
        *returnSize = ans_size;
        return ans;
}
```