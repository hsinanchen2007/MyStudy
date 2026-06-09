### 解题思路
1、快排：找出原数组边界条件；最小值、最大值，便于申请哈希数组的内存空间；

2、利用哈希表，查找是否有相同元素。

PS：做完后才发现有更简单的方法，快排后，直接看相邻两个元素是否相同即可~~~

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return false;
    }

    //int hashArray[1000] = {0}; // hash数组空间开多大呢 ？ 原整数数组有负数该如何处理呢 ？
    // 快排求出原数组中最大、最小整数
    qsort(nums, numsSize, sizeof(int), cmp);

    int minElement, maxElement;
    minElement = nums[0];
    maxElement = nums[numsSize - 1];
    int *hashArray = NULL;

    int hashSize;
    if (minElement < 0) {
        hashSize = maxElement + 1 - minElement;
        hashArray = (int*)calloc(hashSize, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            hashArray[nums[i] - minElement]++;
            if (hashArray[nums[i] - minElement] >= 2) {
                return true;
            }
        }
    } else {
        hashSize = maxElement + 1;
        hashArray = (int*)calloc(hashSize, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            hashArray[nums[i]]++;
            if (hashArray[nums[i]] >= 2) {
                return true;
            }
        }
    }

    return false;
}
```