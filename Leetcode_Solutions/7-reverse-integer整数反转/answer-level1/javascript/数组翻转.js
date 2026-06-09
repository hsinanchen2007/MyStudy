
### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let min = Math.pow(2,31);
    let re = false;
    if(x<0){
        re = true;
        x = -x
    }
    let num = x.toString().split('').reverse().join('');
    return num>min?0:(re?-Number(num):Number(num))
};
```