### 解题思路


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    const len = nums.length
    if (!len) {
        return 0
    }
    let count = 0
    nums.forEach(num => {
        const str = num + ''
        if (!(str.length % 2)) {
        count ++ 
        }
    })
    return count
};
```