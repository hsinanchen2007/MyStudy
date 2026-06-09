```
var sumNums = function(n) {
    return [...new Array(n+1).keys()].reduce((x,y)=>x+y);
};
```
