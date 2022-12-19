1. ### 解题思路
通过对字符串转成数组，利用数组的反转方法，完成反转后再转成字符串。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(item=>{
        return item.split('').reverse().join('')
    }).join(' ')
};
```