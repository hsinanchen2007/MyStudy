1.相同的情况 -1
2. 返回最长的
3. 这么简单 我都有点不相信了

```
var findLUSlength = function(a, b) {
    if(a === b){
        return -1
    }else if(a.length>b.length){
        return a.length
    } else{
         return b.length
    }
};
```
