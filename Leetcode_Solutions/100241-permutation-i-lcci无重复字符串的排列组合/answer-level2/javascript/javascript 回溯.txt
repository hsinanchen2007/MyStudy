```js
var permutation = function(S) {
    const result = []
    const sArr = S.split("")
    const huisu = function(nowArr, optionArr){
        if(nowArr.length === S.length){
            result.push(nowArr.join(""))
        }else{
            for(let i = 0; i < optionArr.length; i++){
                huisu(
                    nowArr.concat(optionArr[i]), 
                    optionArr.slice(0,i).concat(optionArr.slice(i+1))
                )
            }
        }
    }

    huisu([], sArr)
    return result
};
```