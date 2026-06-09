先判断输入的数是正数还是负数，如果是负数先取绝对值在反转，使用Math.pow()方法判断是否超出界限

 if (x < 0) {
                n = -Number(Math.abs(x).toString().split('').reverse().join(''));
                return n > Math.pow(-2, 31) ? n : 0;

            }else{
                n = Number(Math.abs(x).toString().split('').reverse().join(''));
                return n<=(Math.pow(2,31)-1)? n : 0;
            }

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
      if (x < 0) {
                n = -Number(Math.abs(x).toString().split('').reverse().join(''));
                return n > Math.pow(-2, 31) ? n : 0;

            }else{
                n = Number(Math.abs(x).toString().split('').reverse().join(''));
                return n<=(Math.pow(2,31)-1)? n : 0;
            }
   
};
```