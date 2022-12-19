### 解题思路
从1开始遍历到数组长度+1；看数组中是否存在该最小整数，没有则返回

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    for(var i = 1;i<=nums.length+1;i++){
        if(!nums.includes(i)){
            return i
        }
    }
};
```