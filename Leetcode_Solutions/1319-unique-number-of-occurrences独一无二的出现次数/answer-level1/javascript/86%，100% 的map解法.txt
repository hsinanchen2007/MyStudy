```

var uniqueOccurrences = function(arr) {
    let index = 0
    const map = new Map()
    const arrNew = []
    arr.map(v =>{ 
        if(!map.get(v) && map.get(v) !== 0) {
            map.set(v,index);
            if(arrNew[index]) {
                arrNew[index] += 1;
            } else {
                arrNew[index] = 1;
            }
            index++    
        } else {
            arrNew[map.get(v)] += 1
        }
    })
     return arrNew.length===[...new Set(arrNew)].length 
};
```
