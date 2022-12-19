
```
var findLongestChain = function(pairs) {
    if(pairs.length == 0){
        return 0
    }
    pairs.sort((a,b)=>{
        return a[1] - b[1]

    })
    var count = 1
    var cur = pairs[0][1]
    //console.log(cur)
    for(var i = 1;i < pairs.length;i++){
        if(pairs[i][0] > cur){
            count ++
            cur = pairs[i][1]
            //console.log(cur)
        }
    }
    return count

};
```


