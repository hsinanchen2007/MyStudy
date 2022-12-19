### 解题思路
使用了双指针解法。
并做了异常保护：若未找到则返回-1，并做了空指针保护。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, j = 0;
    int *arr = (int *)malloc(sizeof(int)*2);
    arr[0] = -1;
    arr[1] = -1;
    *returnSize = 0;
    j = numbersSize - 1;

    if (NULL == numbers)
    {
        return arr;
    }

    while (i < j)
    {
        if (numbers[i] + numbers[j] < target)
        {
            i++; //若两者之和小于目标值，需要i往后移使得二者之和变大
        } else if (numbers[i] + numbers[j] > target){
            j--; //若两者之和大于目标值，需要j往前移使得二者之和变小
        } else {
            arr[0] = i + 1;
            arr[1] = j + 1;
            *returnSize = 2;
            return arr;
        }
    }

    return arr;
}

```