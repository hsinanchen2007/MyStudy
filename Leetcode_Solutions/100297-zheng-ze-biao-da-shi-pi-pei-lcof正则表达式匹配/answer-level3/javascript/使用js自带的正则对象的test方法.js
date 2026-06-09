### 解题思路
这里使用js自带的正则表达式，新建一个正则对象reg = RegExp("^("+p+")$")，然后reg.test(s)返回即可

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let reg=RegExp("^("+p+")$");
    console.log(reg.source);
    return reg.test(s);
    

};
```