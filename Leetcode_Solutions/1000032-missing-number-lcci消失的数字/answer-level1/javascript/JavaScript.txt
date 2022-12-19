### 解题思路
执行用时 :
60 ms
, 在所有 JavaScript 提交中击败了
99.20%
的用户
内存消耗 :
35.9 MB
, 在所有 JavaScript 提交中击败了
100.00%
的用户

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    return (nums.length + 1) * nums.length /2 - nums.reduce((sum, t) => sum+t) 
};
```