### 解题思路
C语言+栈
1.暴力解法不能满足时间的要求
2.遍历T数组，与栈顶元素进行比较，如果T[i]>栈顶索引对应的元素，则将栈顶元素移除，并且将两者索引差值存储在res数组中。否则的话就将新的元素叠加至栈上。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * TSize) ;
	memset(res, 0, sizeof(int) * TSize);
	int *stack = (int *)malloc(sizeof(int) * TSize) ;
	//int stack[TSize];
	memset(stack, 0, sizeof(int) * TSize);
	int i;
	int top = -1;
	for(i = 0; i < TSize; i++){
        while(top > -1 && T[i] > T[stack[top]]){
            res[stack[top]] = i - stack[top];
            top--;
        }
		stack[++top] = i;
	}
	*returnSize = TSize;
	free(stack);
	return res;
}
```