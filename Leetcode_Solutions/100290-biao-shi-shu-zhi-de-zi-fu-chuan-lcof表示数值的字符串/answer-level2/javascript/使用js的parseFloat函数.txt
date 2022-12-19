### 解题思路
使用转换浮点数的方法进行转换，然后利用js==会自动进行类型转换来进行判断

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
  try{
      let num = parseFloat(s)
      if(isNaN(num)) {
          return false
      }
      if(num == s) {
          return true
      } else {
          return false
      }
  }catch{
      return false
  }
};
```