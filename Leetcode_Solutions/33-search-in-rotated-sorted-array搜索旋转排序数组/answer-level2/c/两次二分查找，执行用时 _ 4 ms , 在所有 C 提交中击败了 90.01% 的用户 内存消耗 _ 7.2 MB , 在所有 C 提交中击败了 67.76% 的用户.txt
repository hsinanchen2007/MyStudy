思路：总共分两步，
1.找到最小值的位置，这里招最小值的位置也是用到了二分查找，其与平常的二分查找的区别在于给lo 和 hi的判断条件不一样，这里需要用到相邻两个元素的关系来比较。
2.根据这个最小值的位置，将数组分为两个子数组，在这两个子数组中，数据都是有序排列的。然后只要判断target在哪个子数组中，二分查找即可。
```
int search(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return -1;
    }
    int minIndex = 0; //最小元素的索引
    int lo = 1;       //当最小元素再最左边，不考虑
    int hi = numsSize - 1;
    int mid = (lo + hi) / 2;
    int res = -1;
    //找到最小值索引
    while (lo <= hi) {
        if (nums[mid] < nums[mid - 1]) {
            minIndex = mid;
            break;
        } else if (nums[mid] < nums[0]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        mid = (lo + hi) / 2;
    }
    //在对应区域上二分搜索目标
    if (minIndex == 0) {
        lo = 0;
        hi = numsSize - 1;
    } else if (target >= nums[0]) {
        lo = 0;
        hi = minIndex - 1;
    } else {
        lo = minIndex;
        hi = numsSize - 1;
    }
    mid = (lo + hi) / 2;
    
    while(lo <= hi) {
        if (nums[mid] == target) {
            res = mid;
            break;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        mid = (lo + hi) / 2;
    }
    return res;
}
```
