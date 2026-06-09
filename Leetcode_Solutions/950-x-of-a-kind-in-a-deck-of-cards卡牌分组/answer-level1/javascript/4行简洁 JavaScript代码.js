
```javascript
var hasGroupsSizeX = function (deck, map = {}) {
    let gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
    for (let i = 0; i < deck.length; i++) {
        map[deck[i]] =  map[deck[i]] ? map[deck[i]] + 1 : 1;
    }
    return Object.values(map).reduce((a, b) => gcd(a, b)) >= 2;
}
```
gcd 函数辗转相除法用来求解两个数的最大公约数
循环 deck 数组将每个数字出现的频次统计在对象中
最后利用 reduce 循环频次数组求数组的最大公约数
最大公约数至少为2则返回 true