### 解题思路

![image.png](https://pic.leetcode-cn.com/7fca7a133837e7704760074dc3e9081ce60ed7f239c0ccf94eaf320100ac8f9d-image.png)


首先用正则匹配出所需的字符串

然后去除首部空格

最后判断是否超出边界，注意要有等于，而且正边界要返回小一个的数字

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function(str) {
    let res = str.match(/^\s*[+-]?\d+/);
    if(!res) return 0;

    res = str.match(/^\s*[+-]?\d+/)[0].trim();
    if(res >= Math.pow(2,31)) {
        return Math.pow(2,31) - 1;
    } else if (res <= Math.pow(-2,31)) {
        return  Math.pow(-2,31)
    } else {
        return  res;
    }
};
```