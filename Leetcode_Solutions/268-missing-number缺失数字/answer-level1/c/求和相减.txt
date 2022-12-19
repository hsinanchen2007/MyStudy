### 解题思路
此处撰写解题思路

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int Sum = 0,i;
    for (i = 0; i < numsSize; i++ ){
        Sum += nums[i];
    }
    return (numsSize*numsSize+numsSize)/2 - Sum;
}
```
由题目可知，假设存在则数组中最大的数字应该为数组的长度，通过求和公式如果一个数字不缺少
        则 
            S = (n + 1) * n / 2
于是求出给出数组的和之后与理论的和S相减即位确实的数字。