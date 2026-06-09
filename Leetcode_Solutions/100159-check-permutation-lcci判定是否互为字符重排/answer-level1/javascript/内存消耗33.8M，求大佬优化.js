### 解题思路
代码又臭又长，先把两个字符串中每个字母出现的次数统计一下，再对比每个字符的次数

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function (s1, s2) {
    let s1Arr = s1.split('');
    let s2Arr = s2.split('');

    if (s1Arr.length !== s2Arr.length) {
        return false;
    }

    let s1Str = {};
    let s2Str = {};
    let len1 = s1Arr.length;
    let len2 = s2Arr.length;

    for (let i = 0; i < len1; i++) {
        if (!s1Str[s1Arr[i]]) {
            s1Str[s1Arr[i]] = 1;
        } else s1Str[s1Arr[i]]++;
    }
    for (let j = 0; j < len2; j++) {
        if (!s2Str[s2Arr[j]]) {
            s2Str[s2Arr[j]] = 1;
        } else s2Str[s2Arr[j]]++;
    }
    for (let k = 0; k < len1; k++) {
        if (s2Str[s1Arr[k]]) {
            if (s1Str[s1Arr[k]] !== s2Str[s1Arr[k]]) {
                return false;
            }
        } else return false;

    }
    return true;
};
```