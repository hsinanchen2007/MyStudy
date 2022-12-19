```
var lengthOfLastWord = function(s) {
    var ret = 0;
    
    for(var i = s.length - 1; i >= 0; i-- ){
        if(s[i] == ' '){
            if(ret) return ret;
        }else{
            ret += 1;
        }
    }
    return ret;
};
```

从后向前遍历，ret哨兵