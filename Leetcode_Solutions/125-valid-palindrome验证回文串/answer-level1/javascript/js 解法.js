### 解题思路
1. 过滤出字母数字。
2. 全部转成小写，或者大写
3. 遍历一半的字符串，比较头尾是否相等。
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const newStr = s.replace(/[^\w]/g, '').toLocaleLowerCase();
    for(let i = 0; i < newStr.length / 2; i++ ){
        if(newStr[i] !== newStr[newStr.length - i - 1]) {
            return false
        }
    }
    return true;
};
```