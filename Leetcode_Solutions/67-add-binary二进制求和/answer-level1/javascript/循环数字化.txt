### 解题思路
先补齐位数
验证a+b+进位除2的商  这里考虑多个相加的情况

### 代码

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let maxLenght = a.length>b.length?a.length:b.length
    let i = maxLenght - a.length
    let j = maxLenght - b.length
    let intoNumber = 0
    let str = ''
    while(i>0){
        a = '0'+a
        i--
    }
    while(j>0){
        b = '0'+b
        j--
    }
    for(let i = maxLenght-1 ;i>=0;i--){
        str=(Number(a[i])+Number(b[i])+intoNumber)%2+str
        if(parseInt((a[i]+b[i]+intoNumber)/2)>0){
            intoNumber = parseInt((Number(a[i])+Number(b[i])+intoNumber)/2)
        }else{
            intoNumber = 0
        }
    }
    if(intoNumber>0){
        str = 1+str
    }
    return str
};
```