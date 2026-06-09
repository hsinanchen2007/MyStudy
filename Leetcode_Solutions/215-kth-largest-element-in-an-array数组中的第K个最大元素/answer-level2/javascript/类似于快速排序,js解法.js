### 解题思路
思路 : 基于数组的第k个数字来调整, 使得比第k个数字小的所有数字都位于数组的左边,
比数组大的元素都位于数组的右边。
这样调整后 , 位于数组中左边第k个数字就是第k大的元素
**总结** : 快速排序思想的利用
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    let start = 0;
    let end = nums.length - 1;
    let index = partition(nums,start,end);
    while(index !== k-1) {
        if(index > k-1) {
            index = partition(nums,start,index-1)
        }
        if(index < k-1) {
            index = partition(nums,index+1,end)
        }
    }
    return nums[k-1];
};


function partition(nums,start,end) {
    let target = nums[start];
    while(start < end) {
        while(nums[end] <= target && start < end) {
            end--;
        }
        nums[start] = nums[end];
        while(nums[start] > target && start < end) {
            start++;
        }
        nums[end] = nums[start];
    }
    nums[start] = target;
    return start;// 目标位置
}


```