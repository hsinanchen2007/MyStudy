### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    // nums [0,1,0,3,12]
    var k = 0 // 仅仅为了交换位置设计的中间量
    for (var i = 0, len = nums.length; i < len; i++) {
        if (nums[i]) {
            if (k !== i) {
                var temp = nums[k]
                nums[k] =  nums[i]
                nums[i] = temp
            }
            k++
            // console.log(nums)
        }
    }
    // [1,0,0,3,12], 第一个0与1交换位置，k++
    // [1,3,0,0,12], 第一个0与3交换位置，k++
    // [1,3,12,0,0], 第二个0与12交换位置，k++
    
};
```