### 解题思路
参考[@liweiwei1419](/u/liweiwei1419/)大神的写法，写的js版本

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    const vals = [1000, 900, 500, 400, 100, 90, 50, 40,10,9,5,4,1]
    const arr = ['M', 'CM', 'D', 'CD', 'C', 'XC','L', 'XL', 'X', 'IX', 'V', 'IV','I']
    let res = '', index = 0
    while(num) {
        while(num >= vals[index]) {
            res += arr[index]
            num -= vals[index]
        }
        index++
    }
    return res
   
};
```