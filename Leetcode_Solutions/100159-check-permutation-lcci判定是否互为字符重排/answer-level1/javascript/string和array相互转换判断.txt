### 解题思路
将两个字符串的所有字符按字母排序, 判断是否相同即可

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function(s1, s2) {
    if (s1.length != s2.length) {
        return false;
    }

    var arr1 = s1.split('').sort();
    var arr2 = s2.split('').sort();

    return arr1.toString() == arr2.toString();
};

```