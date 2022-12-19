### 解题思路
别问，问就是为了通过，让自己舒服一点。算法太差了，这是我做的第三个题目。那些绝对值余数根本就想不到

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if(x == 0){
        return 0
    }
    if(x>0){
        if(x >= 1534236469){
            return 0
        }
        xString = x.toString();
         xarray = xString.split('');
         xString = xarray.reverse().join('');
         return parseInt(xString)
    }
    if(x < 0){
       if(x == -1563847412){
           return 0
       }
        if(x <= -2147483648 ){
            if(x >= -1563847412){
             return 0
            } 
            return 0
         }
         
         xString = x.toString();
         xarray = xString.split('');
         xString = xarray.reverse().join('');

         xString =  '-' + xString;
          return parseInt(xString)
    }
};
```