### 解题思路
1. 遍历数组元素，维护一个单调递增栈；
2. 当前元素值小于栈顶元素值时，栈顶-栈底当作一次交易；栈清空，当前元素入栈；
3. 所有元素遍历完之后，如果满足交易原则——栈顶-栈底，完成最后一次交易；

### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	int *stack;
	int stkLen;
	int i;
	int result;
	
	stack = (int*)calloc(pricesSize, sizeof(int));
	stkLen = 0;
	result = 0;
	
	for (i = 0; i < pricesSize; i++) {
		if ((stkLen == 0) || (prices[i] >= prices[stack[stkLen - 1]])) {
			stack[stkLen++] = i;			
			continue;
		}
		
		if (stkLen > 1) {
			result += prices[stack[stkLen - 1]] - prices[stack[0]];
		}
		stkLen = 0;
		stack[stkLen++] = i;
	}
	if (stkLen > 1) {
		result += prices[stack[stkLen - 1]] - prices[stack[0]];
	}
	return result;
}
```