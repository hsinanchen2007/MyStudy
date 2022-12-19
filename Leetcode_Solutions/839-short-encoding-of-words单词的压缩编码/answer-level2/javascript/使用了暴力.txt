### 解题思路
![image.png](https://pic.leetcode-cn.com/bf2b7a5e51132dc4c1e2e391a3dbec1e6adc3b4c4c3be9985273e75ed965c825-image.png)

速度全国倒数，全排列两两对比，一个是否在另一个尾部。
### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function (words) {
    let totalLen = 0,
        len = words.length;

    words.forEach((val, idx, arr) => {
        totalLen += val.length + 1;
    });

    for (let i = 0; i < len; i++) {
        const strI = words[i];
        const lenI = words[i].length;
        if (strI === "") continue;
        for (let j = i + 1; j < len; j++) {
            const strJ = words[j];
            const lenJ = words[j].length;
            if (strJ === "") continue;
            if (lenI < lenJ) {
                if (strJ.lastIndexOf(strI) === lenJ - lenI) {
                    totalLen -= lenI + 1;
                    break;
                }
            } else if (lenI > lenJ) {
                if (strI.lastIndexOf(strJ) === lenI - lenJ) {
                    totalLen -= lenJ + 1;
                    words[j] = "";
                }
            } else if (lenI === lenJ && strI === strJ) {
                totalLen -= lenI + 1;
                words[j] = "";
            }
        }
    }
    return totalLen;
};
```