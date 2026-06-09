### 解题思路
使用一个set存储已经出现过的和
![leetcode202.png](https://pic.leetcode-cn.com/5b5d28a741772f68cd9ceda3f6151f00db7cb792e4188874b1466cdc38206926-leetcode202.png)

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    if (n < 1) {
        return false
    }
    const set = new Set()
    let str = n.toString()
    let sum = getSum(str)
    set.add(sum)
    while (sum !== 1) {
        sum = getSum(sum.toString())
        // 如果过程中出现已经得到过的和，且不是1，那么必然不会再出现1了，直接返回false
        if (set.has(sum)) {
            return false
        }
        set.add(sum)
    }
    return true
};

function getSum (n) {
    let sum = 0
    let nArr = n.split('')
    nArr.forEach(num => {
        sum += (num * 1 * num)
    })
    return sum
}
```