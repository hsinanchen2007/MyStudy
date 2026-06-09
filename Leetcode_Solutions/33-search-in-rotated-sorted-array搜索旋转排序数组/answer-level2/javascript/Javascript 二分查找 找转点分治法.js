### 解题思路
先遍历一遍，找到转折点spot
然后判断target是否大于start
如果是，则二分查找(start，spot) 
如果不是，则二分查找(spot+1, end).
还可以优化一下，如果数值大于spot，或者小于spot+1说明找不到.

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if(nums.length === 0) return -1;
    let start = 0, end = nums.length - 1, max = 0;
    for(let i=0; i< nums.length;i++){
        if(nums[i] > nums[max]){
            max = i
        }
    }
    if(target > nums[max]) {
        return -1;
    }
    if(max < nums.length-1 && target < nums[max + 1]) {
        return -1;
    }
    if(target > nums[0]) {
        return biSearch(nums,target, 1, max)
    } else if(target < nums[0] ){
        return biSearch(nums,target, max + 1, nums.length - 1)
    } else {
        return 0;
    }
    return -1;
};
var biSearch = function (arr, target, start, end){
    while(start <= end){
        let mid = start + Math.floor((end - start) / 2)
        if(arr[mid] < target) {
            start = mid + 1;
        } else if(arr[mid] > target) {
            end = mid - 1;
        } else{
            return mid;
        }
    }
    return -1;
}
```