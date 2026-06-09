### 解题思路
见代码注释

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i=digitsSize-1; i>-1; --i){
        digits[i] = ++digits[i] % 10; // 加一后取个位
        if(digits[i] != 0) break;// 无进位，循环退出
    }
    *returnSize = digitsSize + (digits[0] == 0); // 首位为0说明最高位进位，长度+1
    int *res = (int *)malloc(*returnSize * sizeof(int));
    res[0] = 1; // 假设最高位为1
    memcpy(res + (digits[0] == 0), digits, digitsSize * sizeof(int)); // 复制digits到res的后digitsSize位中
    return res;
}
```