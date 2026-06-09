### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    for(let i = 0;i < s.length / 2; i++){
      [s[i], s[s.length - 1 - i]] = [s[s.length - 1 - i], s[i]]
    }
    return s
};
```
本身有个高阶函数
```
var reverseString = function(s) {
    return s.reverse()
};
```
