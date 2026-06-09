1、映射
```javascript
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
    let str = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    let res = '';
    let t = n;
    while(t>0) {
        t -= 1;
        // 利用进制转换的思想
        let a = t % 26;
        t = Math.floor(t/26);
        res = `${str[a]}${res}`
    }
    return res
};
```
2、fromCharCode方法

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
    let res="";
    while(n>0){
        let temp = n%26;
        n = Math.floor(n/26);
        if(temp==0){
            temp=26;
            n--;
        }
        res = String.fromCharCode(temp+64)+res;
    }
    return  res; 
};
```