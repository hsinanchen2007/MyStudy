难度是在于题目的理解吧！！！ 看了好几遍； 
解题思路是，遍历匹配abc 全都能匹配的就是true  

```
var isValid = function(S) {
    var str = S;
    while(str.length >= 3 && str.match(/abc/g)!== null){
        str = str.replace(/abc/g,"");
    }
    return (str == "" )?true: false;
};
```
