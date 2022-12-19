### 解题思路
javascript

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let ans = 0
    for (let i = 0; i < S.length; i++) {
        if (J.indexOf(S[i]) >= 0) ans++
    }
    return ans
};
```