### 解题思路
toString求length取余2

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let c = 0, len = nums.length, i = 0;
    for(; i < len; i++){
        (nums[i].toString().length % 2) || c++;
    }
    return c;
};
```