### 解题思路
1）从右到左找到第一个降序数值的位置i，并在右边已遍历位置中找到第1个比它大的数值的位置j，交换这两个数；
对数组从第i + 1个位置开始升序排列即可；
2）如果整个数组从右到左都是升序的，则没有下一个字典序排列，直接对数组升序排列即可。
![image.png](https://pic.leetcode-cn.com/914926a6daaf0ccd9a8038890b66c8a05ec2d07ba7b5c9b30243e94f92a5b3ad-image.png)

### 代码

```c
// 升序排列比较函数
int Check(const void* a, const void* b)
{
    int ta = *(const int*)a;
    int tb = *(const int*)b;
    return (ta > tb) - (ta < tb);
}

// 交换位置
void Swap(int *nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp; 
}

void nextPermutation(int* nums, int numsSize){
    if (nums == NULL || numsSize == 1) {
        return;
    }
    int right = nums[numsSize - 1];
    int rightpos = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        // 从右到左是升序的则更新右值
        if (right <= nums[i]) {
            right = nums[i];
            rightpos = i;
            continue;
        }
        // 降序开始，则从已遍历过得数组中从右到左找第一个大于当前位置数值对应的位置
        for (int j = numsSize - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                rightpos = j;
                break;
            }
        }
        // 交换它们的位置
        Swap(nums, i, rightpos);
        // 后面序列按升序排列
        qsort(nums + i + 1,  numsSize - i - 1, sizeof(int), Check);
        // 已找到则返回
        return;
    }
    // 整数组从右到左都是升序排列，则从左到右升序排列下
    qsort(nums, numsSize, sizeof(int), Check);
}
```