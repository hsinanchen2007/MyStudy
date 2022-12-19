```
var strStr = function(haystack, needle) {
    if(!needle)
        return 0;
    if(haystack.length < needle.length)
        return -1;
    for(let i = 0; i < haystack.length; i++){
        if(haystack[i] === needle[0]){
            let j = i;
            if(needle.length > haystack.length - i)
                return -1;
            for(j = i; j < needle.length + i; j++){
                if(haystack[j] !== needle[j - i]){
                    break;
                }
            }
            if(j === i + needle.length)
                return i;
        }
    }
    return -1;
};
```