```
var removeDuplicates = function(S) {
    let res=[];
    for(let i of S){
        if(res.length>0){
            if(i==res[res.length-1]) res.pop();
            else res.push(i);
        } else res.push(i);
    }
    return res.join("");
};
```
