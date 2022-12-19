### 解题思路
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4





参考　醒着做梦　同学：
思路：如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了

### 代码

```c
int search(int* nums, int numsSize, int target){

    int min=0,max = numsSize -1, mid;
    int top = -1;

    if (nums == NULL || numsSize == 0)
        return -1;
    
    if (numsSize == 1)
        return target == nums[0] ? 0 : -1; 
    
    while (min <= max) {
        mid = (min + max)/2;
        if (target == nums[mid]) {
            return mid;
        }
        //后半部分有序
        if (nums[mid] < nums[numsSize-1]) {
            //tartget 在后半部分里面
            if (target <= nums[numsSize-1] && target > nums[mid]) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        } else {//前半部分有序
            //target在前半部分里面
            if (target >= nums[0] && target < nums[mid]) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }  
    }
    return -1;
}
```