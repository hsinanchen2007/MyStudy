```
var titleToNumber = function(s) {
    //其实就是26进制
    let res=0;
    for(let i=0;i<s.length;++i){
        res+= (s[i].charCodeAt()-64)*Math.pow(26,s.length-1-i);
    }
    return res;
};
```
