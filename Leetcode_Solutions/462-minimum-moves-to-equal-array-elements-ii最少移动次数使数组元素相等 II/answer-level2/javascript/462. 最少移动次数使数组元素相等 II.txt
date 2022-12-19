### 解题思路
此题最要的思考点就是如何找到中位数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    nums.sort((a, b) => a - b);
    let avg = nums[Math.ceil(nums.length/2) - 1];
    return nums.reduce((total, num) => {
        return total+Math.abs(num - avg)
    },0)
};
```