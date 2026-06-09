```
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let Stringx = x.toString().split('')//number => string => arrary
    const xlength = Stringx.length;result=null
    const min = Math.pow(-2, 31);max = Math.pow(2, 31) - 1
    let leftIndex = 0;rightIndex = xlength-1
    const flag = x>0?true:false //正数标志
    if(Stringx[xlength-1]==0){//末尾有0去掉
        Stringx = Stringx.slice(0,xlength-1)
    }
    if(Stringx[0]=='-'){//开头有符号去掉
        Stringx= Stringx.slice(0)  
    }
    if(xlength ==1) return x
    for(let i =0;i<xlength;i++){
        let temp =  Stringx[leftIndex]
        Stringx[leftIndex] = Stringx[rightIndex]
        Stringx[rightIndex] = temp
        leftIndex++;rightIndex--;
        if(leftIndex>rightIndex){ //反转结束
            Stringx= Stringx.join('') //array => string
            result =  flag?parseInt(Stringx):parseInt(`-${Stringx}`) //string=>number
            if(max<result||result<min) return 0
            return result
        }
    }
};
```
