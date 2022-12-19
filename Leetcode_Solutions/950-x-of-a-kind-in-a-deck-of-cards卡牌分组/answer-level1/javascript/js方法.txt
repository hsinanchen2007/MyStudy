```
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function (deck) {
    //  最大公约数
    let gcd = function (u, v) {
        while (v != 0) {
            temp = u % v;
            u = v;
            v = temp;
        }
        return u;
    }
    let minv;
    let count = {};
    for (let i = 0; i < deck.length; i++) {
        if (!count[deck[i]]) {
            count[deck[i]] = 0
        }
        count[deck[i]]++;
    }
    for (let key in count) {
        let v = count[key]
        if (minv == undefined) {
            minv = v;
            continue;
        }
        if (minv % v == 0 || v % minv == 0) {
            minv = Math.min(minv, v);
        } else {
            minv = gcd(v > minv ? v : minv, v > minv ? minv : v);
            if (minv == 1) {
                return false;
            }
        }
    }
    return minv >= 2;
};
```
减少了一些求最大公约数的次数，不知道还有没有更好的方法
