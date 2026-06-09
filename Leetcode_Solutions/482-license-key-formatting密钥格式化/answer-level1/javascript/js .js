### 解题思路
先 转为大写 再 倒序排列 去-
在循环中将K位字符的倒序 依次写入数组
最后将数组再倒序排列 加-

### 代码

```javascript
/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) {
    var str = S.toUpperCase().split('').reverse().join('');
    str = str.split('-').join('');
    var arr = [];
    var j =0;
    for(var i = 0; i < str.length; i+=K){
       arr[j] = str.slice(i,i+K).split('').reverse().join('');
       j++;
    }
    return arr.reverse().join('-');
};
```