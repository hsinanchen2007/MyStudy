### 解题思路
充分利用题目给出的有序数组条件，从有序数组的两头不断逼近，以得出最终结果。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    if (numbers == NULL) {
        return NULL;
    }
    int i = 0, j = numbersSize - 1;
    int *result = (int *) malloc (2 * sizeof(int));
    while (i < j) {
        if (numbers[i] + numbers[j] > target) {
            --j;
        } else if (numbers[i] + numbers[j] < target) {
            ++i;
        } else {
            result[0] = i + 1;
            result[1] = j + 1;
            *returnSize = 2;
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
}
```