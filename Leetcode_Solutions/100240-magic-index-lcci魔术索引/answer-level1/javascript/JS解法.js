### 解题思路
做循环判断；
若符合条件，中止循环，经过三元运算符判断为i；
若没有符合，此时i等于nums.length，经三元运算符判断为-1。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMagicIndex = function(nums) {
    for(var i=0;i<nums.length;i++){
        if(nums[i]===i)break
    }
    return i===nums.length?-1:i
};
```