### 解题思路
先考虑暴力，然后在暴力的基础之上，看有没有单调变化，注意到要找到最小的一对i和j，那随着i的增加，j一定是单调递减，所以可以用双指针进行优化。
i从头开始，j从尾开始，j检查到i为止，找到numbers[i] + numbers[j]最接近target的值（也就是numbers[i] + numbers[j] >= target的时候j--继续查找），找到的第一个就返回。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    
    int *returnValues = (int *) malloc(sizeof(int) * 2);
    if (returnValues == NULL)
    {
        return 0;
    }
    
    *returnSize = 2;
    
    int i, j;

    
    for (i = 0, j = numbersSize - 1; i < numbersSize; i ++)
    {
        while(j - 1 > i && numbers[i] + numbers[j - 1] >= target)
        {
            j --;
        }
        if (numbers[i] + numbers[j] == target)
        {
            returnValues[0] = i + 1;
            returnValues[1] = j + 1;
            return returnValues;
        }
    }

    return 0;
}
```