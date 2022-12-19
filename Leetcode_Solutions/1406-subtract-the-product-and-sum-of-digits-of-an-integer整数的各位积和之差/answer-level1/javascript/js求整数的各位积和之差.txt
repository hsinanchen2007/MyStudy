### 解题思路
看到题目，我想到的是类型转换。先将**n**转换为字符串类型，在转换为数组。
通过**join**把数组转换为字符串
使用**eval**计算字符串的值。

第一次在leetcode上刷题，分享下这道题第一次的做法。
### 代码

假设 n = 234
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    if(typeof n !=='number') return;
    let num = n.toString(),arr=[],x,y,result;
    for(let i=0;i<num.length;i++){
        arr.push(parseInt(num[i]));
    }
    x = eval(arr.join('*')); // arr = '2*3*4' x = 24
    y = eval(arr.join('+')); // arr = '2+3+4' y = 9
    return result = x - y;
};
```