### 解题思路

1、首先二分值域，找到旋转数组的分界点。
即我们找到原始数组最小值，在旋转数组中的索引位置。以nums = [4,5,6,7,0,1,2], 
target = 0为例，通过调用函数find_rotate_index，我们找到了最小值的索引idx为4。

2、有了最小值分界点位置后，我们就能获得整个数组的最大值max和最小值min以及最右端值
nums[numsSize - 1]，接下来就和普通二分法一模一样了，不过之前我们可以对一些
特殊条件提前判断，比如说target < min, target > max，则直接返回-1。否则target
就只可能在[0, idx - 1]、 [idx, numsSize - 1]两个区间之一寻找，判断的条件是：
a、target <= nums[numsSize],则去[idx, numsSize - 1]中二分查找。
b、否则去[0, idx - 1]中查找，这样我们就考虑到所有情况了。

是不是思路很easy，记得点赞哦！！！

### 代码

```c

//值域二分法，找最小分界点
int find_rotate_index(int q[], int len)
{
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q[mid] <= q[len - 1]){
            r = mid;  //q[mid]小于等于最右端值，那么最小值所在位置，一定在[l, mid]之间。
        } else {
            l = mid + 1;
        }
    }
    return l;
}
//二分索引，查找目标值
int find(int q[], int a, int b, int target)
{
    int l = a, r = b;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (q[mid] == target) return mid;
        else if (q[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    if (nums == NULL || numsSize == 0) return -1;
    int min_idx = find_rotate_index(nums, numsSize);
    printf("%d\n", min_idx);

    //二分法找目标值
    if (min_idx == 0) return find(nums, 0, numsSize - 1, target);
    if (target < nums[min_idx]) return -1;
    if (target > nums[min_idx - 1]) return -1;
    if (target <= nums[numsSize - 1]) return find(nums, min_idx, numsSize - 1, target);
    else return find(nums, 0, min_idx - 1, target);
}
```