一看就会


```
var lengthOfLongestSubstring = function(s) {
   
            var res1 = [];
            var max = 0;

            for(var i = 0; i < s.length; i++){
                if(res1.indexOf(s[i]) < 0){s
                    res1.push(s[i])
                }else{
                    if(res1.length > max){
                        max = res1.length
                    }
                    
                    if (res1.indexOf(s[i]) == 0) {
                        res1.splice(res1.indexOf(s[i]) , 1)
                    }else{
                        res1.splice(0, res1.indexOf(s[i])+1)
                    }
                    res1.push(s[i])
                } 
            }
            return max > res1.length ? max : res1.length
       
    };

```

