
```
var findTheDifference = function(s, t) {
    var map = {};
    for(var i = 0; i < s.length; i++){
        if(map[s[i]]){
            map[s[i]]++;
        }else{
            map[s[i]] = 1;
        }
    }
    
    for(var i = 0; i < t.length; i++){
        if(map[t[i]]){
            map[t[i]]--;
        }else{
            return t[i];
        }
    }
};
```
