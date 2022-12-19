```
var findOcurrences = function(text, first, second) {
    var textArr = text.split(' ')
    var addArr = []
    var result = []
    addArr.push(first, second)
    for(var i=0; i<textArr.length; i++){
        if(textArr[i] == addArr[0] && textArr[i+1] == addArr[1] && Boolean(textArr[i+2]) != false){
            result.push(textArr[i+2])
        }
    }
    return result 
};
```
1. 同时遍历三个数
2. 用时：80ms
3. 内存：33.9MB（js100%）
