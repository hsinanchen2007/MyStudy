### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/7cab0421a2a3c2ee5177635f5c805d6f013fb94c0a11e9791483e20a0b41bcd3-image.png)
维护一个单调栈，由栈顶至栈底由小到大。栈中存放元素的下标（保证唯一）,
（1）当遍历到数组的一个新的元素时，若栈顶比该元素小，那么对此时的栈顶来说，找到了下一个更大元素，便从栈中弹出。
继续判断栈顶是否小于该元素，小于则弹出，直到栈为空或栈顶大于该元素。这时记录结果为当前元素的下标减去栈顶元素(存放的是下标)
（2）当栈为空或栈顶大于该元素时，直接将该元素入栈。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 30000
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *stack = calloc(MAX_NUM, sizeof(int));/* 模拟栈 */
    int *result = calloc(TSize, sizeof(int)); /* 默认清零 */
    int top = -1;/* 模拟栈顶 */
    
    for (int i = 0; i < TSize; i++) {
        while(top > -1 && T[stack[top]] < T[i]) {
            result[stack[top--]] = i - stack[top]; /* 记录结果，结果为当前元素的下标减去栈顶元素*/
        }
        stack[++top] = i;/* 存放元素下标 */
    }

    *returnSize = TSize;
    free(stack);
    return result;
}
```