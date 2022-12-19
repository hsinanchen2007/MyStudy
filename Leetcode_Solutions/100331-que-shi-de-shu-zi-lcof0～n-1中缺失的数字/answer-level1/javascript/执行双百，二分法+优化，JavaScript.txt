### 解题思路
![image.png](https://pic.leetcode-cn.com/f69f86e1b52491f64e4da8f9b987eb6b2148ca3dc34cfa26721ebd271018b951-image.png)
如果nums本身就是有序的，就不用查找位置，因为位置就是最后一个数后面的位置。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    //二项查找
    if(nums.length - 1 === nums[nums.length - 1]) return nums.length;//如果就是有序，直接返回最后一个数
    let left = 0, right = nums.length - 1;
    while(left <= right) {
        let mid = left + parseInt((right - left) / 2);
        mid === nums[mid] ? left = mid + 1 : right = mid - 1;
    }
    return left;
};
```