### 解题思路
双索引夹逼。和偏大，大索引向前扫；和偏小，小索引向后扫。
注意：该题结果索引的修正+1。
时间复杂度O(n)。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int *ret = (int*)malloc((2*sizeof(int)));

    if(numbersSize <= 1)
    {
        *returnSize = 0;
        return ret;
    }
    ret[0] = 0;
    ret[1] = numbersSize-1;
    while(ret[0] < ret[1])
    {
        if(numbers[ret[0]] + numbers[ret[1]] > target)
        {
            ret[1]--;
        }
        else if(numbers[ret[0]] + numbers[ret[1]] < target)
        {
            ret[0]++;
        }
        if((numbers[ret[0]] + numbers[ret[1]] == target)&&(ret[0] < ret[1]))
        {
            ret[0]++;   //索引修正+1
            ret[1]++;
            *returnSize = 2;
            return ret;
        }
    }
    *returnSize = 0;
    return ret;
}
```