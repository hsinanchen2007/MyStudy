### 解题思路
题干中已经给出字符和整数的映射表，建立映射表，通常情况下只需将字符串分割成数组，然后利用 reduce 进行累加即可
题干中的特殊情况，有规律可循，即假如第 index 个字符串为特殊情况中的左值，且 index + 1 个字符串为特殊情况中的右值时，需要将总和减去第 index 个字符串对应的整数值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
    const mapping = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    const hardCodeMapping = {
        "I": ["V", "X"],
        "X": ["L", "C"],
        "C": ["D", "M"]
    }

    const result = String(s).split('').reduce((preVal, currStr, index, arr) => {
        if (currStr in hardCodeMapping && index < arr.length - 1 && hardCodeMapping[currStr].includes(arr[
                index + 1])) {
            return preVal - mapping[currStr]
        }
        return preVal + mapping[currStr] 
    }, 0)
    return result
};
```