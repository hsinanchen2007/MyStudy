### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 10005

static int list[MAX_NODE];
static int ans[MAX_NODE];

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
	int loop;
	int count = 0;
	int index = 0;

	memset(ans, -1, sizeof(ans));
	if (!nums || numsSize <= 1) {
		*returnSize = numsSize;
		return ans;
	}
	list[index++] = 0;
	loop = 1;
	while(1) {
		while(index - 1 >= 0 && nums[list[index - 1]] < nums[loop]) {
			ans[list[index - 1]] = nums[loop];
			index--;
		}
		list[index++] = loop;
		if (loop == numsSize - 1) {
            loop = -1;
			count++;
		}
		if(count == 2)
			break;
        loop++;
	}
	*returnSize = numsSize;
	return ans;
}
```