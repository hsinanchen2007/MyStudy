### 解题思路
纯C 双指针

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0;
    int right = numbersSize - 1;
    int sum = 0;
    int* pRes = (int*)malloc(2 * sizeof(int));
    pRes[0] = pRes[1] = -1;
    *returnSize = 2;

    while (left < right)
    {
        sum = numbers[left] + numbers[right];

        if (sum == target)
        {
            pRes[0] = left + 1;
            pRes[1] = right + 1;
            return pRes;
        }
        else if (sum < target)
        {
            left++;
        }
        else if (target < sum)
        {
            right--;
        }
    }

    return pRes;
}
```