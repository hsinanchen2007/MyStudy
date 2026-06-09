### 解题思路
二分查找的一个变形，因为是旋转数组，可以选用mid来比较start(开始)或者end(结束)元素。这里选择end
1、mid元素大于end，说明从mid到end的趋势是递减的，所以最小值出现在mid的右边
2、mid元素小于end，说明从mid到end的趋势是递增的，所以最小值出现在mid的左边
3、用if(){} else if(){},而不是if(){}else{},是看了之前二分法的一个避坑指南，建议else里也写入判断条件

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let start = 0;
    let end = nums.length - 1;

    while(start < end) {
        const mid = parseInt(start + (end - start) / 2);

        if(nums[mid] > nums[end]) {
            start = mid + 1;
        }else if( nums[mid] < nums[end]) {
            end = mid;
        }
    }

    return nums[start];
};
```