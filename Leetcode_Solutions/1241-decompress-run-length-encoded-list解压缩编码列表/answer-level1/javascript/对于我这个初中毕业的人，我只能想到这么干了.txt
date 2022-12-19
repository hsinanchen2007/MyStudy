### 解题思路
首先创建一个指针，每次循环，指针右移两个位置，按指针当前位置的数值，向结果数组中push相应个数的数值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    let l = 0, len = nums.length, result = []
    if ((len % 2) !== 0) {
        return
    }
    while (l < len) {
        for (let i = 0; i < nums[l]; i++) {
            result.push(nums[l+1])
        }
        l += 2
    }
    return result
};
```