```js
var countBinarySubstrings = function(s) {
    //res存储相邻连续字符串的个数
    let res = [];
    let temp = s[0];
    let count = 0;
    for(let i of s){
        if(i !== temp) {
            res.push(count);
            temp = i;
            count = 0;
        }
        count++;
    }
    res.push(count);
    let total = 0;
    for(let i = 0; i < res.length-1; i++){
        total += Math.min(res[i],res[i+1]);
    }
    return total;
};
```
