### 解题思路
转化成key value模式，也就是变成字典，后面的就简单了

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function (words) {
    const mors = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."];
    const morsStr = Array.from({ length: 26 }).reduce((t, i, idx) => {
        t[String.fromCharCode(idx + 97)] = mors[idx];
        return t;
    }, {});
    let arr = [];
    const ans = words.reduce((t, i, idx) => {
        let mw = i.split('').reduce((wt, w) => wt += morsStr[w], '');
        if (arr.indexOf(mw) === -1) {
            t++;
            arr.push(mw)
        }
        return t
    }, 0)
    return ans;
};
```