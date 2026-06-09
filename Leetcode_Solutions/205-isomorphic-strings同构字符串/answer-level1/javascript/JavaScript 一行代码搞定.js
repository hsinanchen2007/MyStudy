### 解题思路
两个方法思路是一样的
indexOf 得到对应字母第一个字母的下标 判断两者是否相等

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
// 方法一
var isIsomorphic = function(s, t) {
    return s.split('').reduce((res, ele, index) => { if(s.indexOf(s[index]) != t.indexOf(t[index])){ return false;} else return res }, true)
};
// 方法二
var isIsomorphic2 = function(s, t) {
    // if (s.length != t.length) return false
    for (let i = 0; i < s.length; i++) {
        if(s.indexOf(s[i]) != t.indexOf(t[i])){
            return false;
        }
    }
    return true;
}
```