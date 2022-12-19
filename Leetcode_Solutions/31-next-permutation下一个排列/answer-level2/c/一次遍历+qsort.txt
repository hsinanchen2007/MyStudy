### 解题思路
1、从后往前遍历，找到第一个nums[i] < nums[i + 1]，的位置i;
2、通过步骤1知道i以后的位置都是单调递减的，因此后后面队列中找到第一个比他大的数，位置为j；
3、交换位置i和位置j上面的两个数；
4、从i+1位置开始，后面的数按照递增排序，最终的结果就是要找到的下一个比当前数大的数；
![image.png](https://pic.leetcode-cn.com/4f23891452f096d7512d65cdd1be25dab5a88b649a789a45340105dad0e37959-image.png)

### 代码

```c
static int Compare(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

static int GetLeft(int* nums, int numsSize)
{
    int left = numsSize - 2;
    while (left >= 0) {
        if (nums[left] < nums[left + 1]) {
            break;
        }
        left--;
    }
    return left;
}

static int GetRight(int* nums, int numsSize, int left)
{
    int right;
    for (right = left + 1; right < numsSize; right++) {
        if (nums[left] >= nums[right]) {
            break;
        }
    }
    return right - 1;
}

static void swapNum(int* nums, int left, int right)
{
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

void nextPermutation(int* nums, int numsSize)
{
    if ((numsSize == 0 || (nums == NULL))) {
        return;
    }
    int left = GetLeft(nums, numsSize);
    if (left == -1) {
        qsort(nums, numsSize, sizeof(int), Compare);
        return;
    }
    int right = GetRight(nums, numsSize, left);
    swapNum(nums, left, right);
    qsort(nums + left + 1, numsSize - left - 1, sizeof(int), Compare);
}
```