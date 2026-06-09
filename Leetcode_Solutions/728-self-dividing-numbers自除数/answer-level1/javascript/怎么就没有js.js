虽然比较耗时费力，但是是一种思路
```
var selfDividingNumbers = function(left, right) {
    const arr = []
    for (let i = left; i <= right; i++){
        if (i < 10){
           arr.push(i) 
        } else {
            console.log(i)
            const items = (i+'').split('')
            let pass = true
            items.forEach(item=>{
                if (i % item != 0){
                    pass = false
                }
            })
            if (pass){
               arr.push(i)  
            }
        }
    }
    return arr
};
```
