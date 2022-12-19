### 解题思路
![image.png](https://pic.leetcode-cn.com/1c0ed7297f98399e3e1ecbef4ad8c33ef4506dbba542f586ff04b47ce8b5ca3a-image.png)

偷懒了，js的split和join大法，转换到array处理起来方便。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(" ");
    let ret = [];
    arr.forEach(val => {
        if (val != "") {
            ret.unshift(val);
        }
    })
    return ret.join(" ");
};
```