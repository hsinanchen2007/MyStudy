1.用数组记录出现次数
2.求出现次数的最大公约数，公约数不为 1 则为 true

```
var hasGroupsSizeX = function (deck) {
    var arr = new Array(10001).fill(0);
    for (let i = 0; i < deck.length; i++) {
        arr[deck[i]]++;
    }
    var temp = 0;
    var judge = true;
    for (let i = 0; i < 10001; i++) {
        if (arr[i]) {
            temp = gcd(arr[i], temp);
            if (temp === 1) { judge = false; break; }
        }
    }
    return judge;
};

function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b)
}
```
