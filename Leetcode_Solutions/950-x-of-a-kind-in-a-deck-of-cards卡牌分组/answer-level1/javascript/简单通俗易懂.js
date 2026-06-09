### 解题思路
根据题意分析，依次获取所有数字出现的次数，这些次数都应该大于`2`且最大公约数也要大于`2`，则返回`true`，否则返回`false`

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    // 依次获取每个数字出现的次数并存入 obj对象
    let obj = {}
    for (let i = 0; i < deck.length; i++) {
        const d = deck[i]
        if (d != parseInt(d)) {
            return false
        }
        obj[d] = typeof obj[d] == "number" ? obj[d] + 1 : 1
    }
    // 获取value值 存入数组
    let arr = []
    for (const k in obj) {
        const e = obj[k]
        arr.push(e)
    }
    // 从小到大排序
    arr.sort((a, b) => {
        return a - b
    })
    // 最小值小于2，返回false
    if (arr[0] < 2) {
        return false
    }
    // 计算最大公约数， 小于2的返回false
    for (let i = 0; i < arr.length - 1; i++) {
        const num = gcd(arr[i], arr[i+1])
        if (num < 2) {
            return false
        }
    }
    return true
};
// 获取最大公约数函数
function gcd (a,b){
    var r = a % b
    return b == 0 ? a : gcd(b,r)
}
```