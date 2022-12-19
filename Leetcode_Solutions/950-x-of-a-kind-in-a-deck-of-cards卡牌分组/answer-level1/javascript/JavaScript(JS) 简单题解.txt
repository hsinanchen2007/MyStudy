### 解题思路
先桶计数每个数字出现的次数，然后计算每个数次出现次数的最大公约数，如果最大公约数大于等于2，则返回true.

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function (deck) {
    // 辗转相除法求最大公约数
    const gcd = (x, y) => {
        return x == 0 ? y : gcd(y % x, x);
    }
    if (deck.length < 2) return false
    let map = new Map();
    // 桶排序计数,统计每个元素出现的次数
    for (let i = 0; i < deck.length; i++) {
        if (map.has(deck[i])) {
            map.set(deck[i], map.get(deck[i]) + 1);
        } else {
            map.set(deck[i], 1)
        }
    }
    let rank = Array.from(map.values());
    let max = rank[0];
    for (let i = 1; i < rank.length; i++) {
        max = gcd(max, rank[i])
    }
    return max >= 2
};

```