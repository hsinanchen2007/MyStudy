### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var nums = [];
var sum = 0;
var a = 0;
var findMedianSortedArrays = function(nums1, nums2) {   
    nums = nums1.concat(nums2);
for (var i=0; i<nums.length; i++){
    for (var j=0; j<nums.length; j++){  
        if (nums[i] < nums[j]){
            var temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
    if (nums.length % 2 == 0) {
        sum = nums[nums.length/2 - 1] + nums[nums.length/2];
        a = sum/2;
    } else {
        a = nums[(nums.length-1)/2];
    }
    return a;
};
```