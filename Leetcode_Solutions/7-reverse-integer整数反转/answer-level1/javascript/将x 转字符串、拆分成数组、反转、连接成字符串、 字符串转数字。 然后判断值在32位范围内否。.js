### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let reverNum ;
    reverNum = parseInt(x.toString().split('').reverse().join(''));
    console.log('reverNum',reverNum);
    let min = '-' + Math.pow(2,31);
    let max = Math.pow(2,31) -1 ;
    if ( reverNum > min && reverNum < max ){ 
        return x > 0 ? reverNum : -reverNum;
    }else {
        return 0;
    }
};
```