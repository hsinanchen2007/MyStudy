### 解题思路
统计每个数字出现次数 -> 取最大公约数

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    let map = {}
    deck.forEach((val) => {
        if(map[val]){
            map[val]++
        }else{
            map[val] = 1
        }
    })
    let x = 0
    Object.values(map).forEach(val => {
            x = gcd(x, val)
    })
    return x >= 2
};
function gcd(num1, num2){
    return num1 === 0 ? num2 : gcd(num2 % num1, num1)
}
```