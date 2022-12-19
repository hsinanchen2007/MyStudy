### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int index1 = 0;
    int index2 = numbersSize - 1;
    int *nums = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    while (index1 < index2) {
        if (numbers[index1] + numbers[index2] < target) {
            index1++;
        } else if (numbers[index1] + numbers[index2] > target) {
            index2--;
        } else {
            nums[0] = index1 + 1;
            nums[1] = index2 + 1;
            return nums;
        }
    }
    return 0;
}
```