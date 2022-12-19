递归

```js
var gcdOfStrings = function (str1, str2) {
    let len1 = str1.length;
    let len2 = str2.length;
    if (len1 == len2) {
        if (str1 == str2) {
            return str1
        } else {
            return ''
        }
    } else if (len1 > len2) {
        let temp = str1.replace(str2, '');
        return gcdOfStrings(temp, str2)
    } else {
        let temp = str2.replace(str1, '');
        return gcdOfStrings(temp, str1)
    }
};
```
