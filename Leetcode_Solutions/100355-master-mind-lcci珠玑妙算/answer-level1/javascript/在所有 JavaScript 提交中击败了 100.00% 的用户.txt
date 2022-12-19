### 解题思路

### 代码

```javascript
/**
 * @param {string} solution
 * @param {string} guess
 * @return {number[]}
 */
var masterMind = function (solution, guess) {
    let gObj = {}
    let arr = [0, 0]
    let sObj = {}
    for (let i = 0; i < solution.length; i++) {
        if (solution[i] === guess[i]) {
            arr[0] += 1
        }
        gObj[guess[i]] = !gObj[guess[i]] ? 1 : ++gObj[guess[i]]
        sObj[solution[i]] = !sObj[solution[i]] ? 1 : ++sObj[solution[i]]
    }
    let keys = Object.keys(sObj)
    for (let i = 0; i < keys.length; i++) {
        if (gObj[keys[i]] && sObj[keys[i]]) {
            arr[1] += Math.min(gObj[keys[i]], sObj[keys[i]])
        }
    }
    arr[1] = arr[1] - arr[0]
    return arr
};
```