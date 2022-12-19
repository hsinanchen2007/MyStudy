逐层计算中间的值，手动补齐两侧的1
```
var getRow = function(rowIndex) {
    if(rowIndex == 0) return [1]
    let arr = [1,1],result = [],index = 1;
    
    while(index < rowIndex){
        for(let i=0;i<index;i++){
            result.push(arr[i] + arr[i+1])
        }
        result.unshift(1)
        result.push(1)
        arr = result
        result = []
        index++
    }
    return arr
};
```
