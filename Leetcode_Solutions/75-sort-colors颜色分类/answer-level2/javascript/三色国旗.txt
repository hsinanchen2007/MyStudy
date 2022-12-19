### 解题思路
根据官解的思路写的js

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var p0 = 0,cur=0, p2 = nums.length-1
    function swap(a,b) {
        var temp = nums[a]
        nums[a] = nums[b];
        nums[b] = temp

    }
    while(cur<=p2) {
        if (nums[cur] === 2) {
            //p2代表2的左边界，指针左移
            swap(cur,p2)
            p2--
        } else if (nums[cur] === 0) {
            // p0代表0的右边界，p0右移，当前值右移 
            swap(cur, p0)
            p0++
            cur++
        } else {
            // cur代表1的指针，遇到1时，cur右移
            cur++
        }
    }
    console.log(nums)
    return nums
};
```