```
var detectCapitalUse = function(word) {
    arr = []
    for(i in word){
        if(word[i].toLowerCase() !== word[i]){
            arr.push(i)
        }  
    }
    if(arr.length === word.length){
        return true
    }else if(arr.length===1 && arr[0]==='0' || arr.length === 0){
        return true
    }else{
        return false
    }
};
```