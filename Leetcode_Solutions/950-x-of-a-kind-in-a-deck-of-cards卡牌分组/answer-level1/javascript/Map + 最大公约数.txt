### 解题思路
![image.png](https://pic.leetcode-cn.com/9c08712ed4e4c7bf0dace511ceab161645fed2849b683251dbae59ec39e9e0b4-image.png)

比想象中难一些，居然提交了5次才AC，轻敌了。

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function (deck) {
    if (deck.length <= 1) return false;

    let cntMap = new Map(),
        gcdVal = 0;

    deck.forEach((val, idx, arr) => {
        if (!cntMap.has(val)) {
            cntMap.set(val, 1);
        } else {
            let cnt = cntMap.get(val) + 1;
            cntMap.set(val, cnt);
        }
    });

    const gcd = (a, b) => {
        return (!b) ? a : gcd(b, a % b);
    }

    for (let cnt of cntMap.values()) {
        if (cnt === 1) return false;
        if (gcdVal === 0) {
            gcdVal = cnt;
        } else {
            gcdVal = Math.min(gcd(gcdVal, cnt), gcdVal);
        }
    }
    if (gcdVal === 1) return false;
    return true;
};

```