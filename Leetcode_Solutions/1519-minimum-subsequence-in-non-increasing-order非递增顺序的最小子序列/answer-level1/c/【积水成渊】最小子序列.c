### 解题思路
调试出错点，技巧
一、出错点
1.1 快速排序中，漏写返回条件
if (left > right) return;
1.2 对字符串作为子函数入参的逻辑没有掌握
传入字符串指针，即可以在内部修改字符串值；
1.3 在计算count值时，没有对i进行自加，导致出错；
（切实需要增加bug free的能力）
1.4 在快速排序中，while循环中，i与j之间的判断条件“i != j”与“i < j”是否等价；
1 现在理解是等价的；

二、技巧
2.1 分析问题的题眼
1 长度最小，元素之和最大，非递增 ---> 推出是递减排序，然后取中间值；


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int *nums, int numSize, int left, int right) {
    int i, j, tmp;
    int t;
    if (left > right) {
        return;
    }
    i = left;
    j = right;
    tmp = nums[left];
    while (i != j) {
        while (nums[j] <= tmp && i < j) {
            j--;
        }
        while (nums[i] >= tmp && i < j) {
            i++;
        }
        if (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    nums[left] = nums[i];
    nums[i] = tmp;
    quickSort(nums, numSize, left, i - 1);
    quickSort(nums, numSize, i + 1, right);
    return;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize){
    int i, sum, average, count;

    // 计算总和及平均值
    sum = 0;
    average = 0;
    for (i = 0; i < numsSize; i++) {
        sum = sum + nums[i];
    }
    average = sum / 2;
    // 进行排序
    quickSort(nums, numsSize, 0, numsSize - 1);
    // 进行求解
    i = 0;
    count = 0;

    while (i < numsSize) {
        count = count + nums[i++];
        if (count > average) {
            break;
        }
    }
    *returnSize = i;
    return nums;
}
```