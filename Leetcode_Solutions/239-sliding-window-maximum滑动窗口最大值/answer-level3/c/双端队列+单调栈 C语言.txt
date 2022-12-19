### 解题思路
维护一个双端队列，单调递减栈。

栈底是当前遍历到的最大值数组ID，每次有数据入栈后都检查当前栈底的ID是否超出滑动窗口：若超出，栈底后移。
当滑动窗口覆盖满k个元素后每次将栈底元素输出到保存结果的数组里。


### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
	int i;
	int *stack;
	int StkTail;
	int *returnArray;
	int stkHead;
	int returnLen;
	
	if ((nums == NULL) || (numsSize == 0) || (k == 0)) {
		*returnSize = 0;
		return NULL;
	}
	
	*returnSize = numsSize - k + 1;
	stack = (int*)malloc(sizeof(int) * (numsSize));
	memset(stack, 0, sizeof(int) * (numsSize));
	
	returnArray = (int*)malloc(sizeof(int) * (*returnSize));
	memset(returnArray, 0, sizeof(int) * (*returnSize));
	
	returnArray[0] = INT_MAX;
	StkTail = 0;
	stkHead = 0;
	returnLen = 0;
	for (i = 0; i < numsSize; i++) {
		if ((StkTail == 0) || (nums[i] <= nums[stack[StkTail - 1]])) {
			stack[StkTail] = i;
			StkTail += 1;
			StkTail %= numsSize;
			
			if (stack[stkHead] == i - k) {
			stkHead += 1;
			stkHead %= numsSize;
			}
			
			if (i >= k - 1) {
				returnArray[returnLen++] = nums[stack[stkHead]];
			}
			continue;
		}
		
		while ((StkTail > stkHead) && (nums[i] > nums[stack[StkTail - 1]])) {
			StkTail -= 1;
		}
		
		stack[StkTail] = i;
		StkTail += 1;
		
		if (stack[stkHead] == i - k) {
			stkHead += 1;
			stkHead %= numsSize;
		}
		
		if (i >= k - 1) {
			returnArray[returnLen++] = nums[stack[stkHead]];
		}		
	}
	
	return returnArray;
}
```