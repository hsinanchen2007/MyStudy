### 解题思路
![image.png](https://pic.leetcode-cn.com/50b10f48f21de81dd06424a4ac9b3cb7a111669fe5a2955fd4675888ce418fb5-image.png)

- 转载答案
- num & 15 取余操作
- num >> 4 是缩减字符操作

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var toHex = function(num) {
    if(!num){return '0'}
    let res = ''
    const tmp = '0123456789abcdef'
    while(num != 0 && res.length < 8 ){
        res = tmp[num & 15] + res
        num >>= 4
    }
    return res
};
```