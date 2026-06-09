### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function (s) {
    //   try{
    //       let num = parseFloat(s)
    //       if(isNaN(num)) {
    //           return false
    //       }
    //       if(num == s) {
    //           return true
    //       } else {
    //           return false
    //       }
    //   }catch{
    //       return false
    //   }
    let num = parseFloat(s);
    if(isNaN(num)) {
        return false;
    }
    if(num == s) {
        return true;
    } else {
        return false
    }
};

```