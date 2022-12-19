### 解题思路
直接算就行了没啥特别思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function (n) {
    let nums = []
    while (n >= 10) {
        nums.push(n % 10)
        n = parseInt(n / 10)
    }
    nums.push(n)
    let sum = nums[0]
    let multi = nums.reduce((pre, val) => {
        sum += val
        return pre * val
    })
    return multi - sum
};
```