### 解题思路
遍历较短的字符串,然后在较长的字符串寻找当前字符,记录下索引,下一次寻找就从记录的索引后开始查找

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    var temp = -1
    for(var i =0;i<s.length;i++){
      let indexS = s[i];
      let findIndex = t.indexOf(indexS, temp + 1);
      if(findIndex===-1){
        return false
      }else {
        temp = findIndex
      }
    }
    return true
};
```