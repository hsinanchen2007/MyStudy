### 解题思路
求和

### 代码

```javascript
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function (moves) {
    let r = 0, c = 0, rMap = { L: -1, R: 1 }, cMap = { U: 1, D: -1 }
    for (let i = 0; i < moves.length; i++) {
        let l = moves[i]
        if (rMap[l]) {
            r += rMap[l]
        }
        if (cMap[l]) {
            c += cMap[l]
        }
    }
    return r === 0 && c === 0
};
```