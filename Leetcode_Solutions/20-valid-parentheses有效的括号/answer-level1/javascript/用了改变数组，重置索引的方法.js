```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = {
        "(": 0,
        "[": 1,
        "{": 2,
        "}": 3,
        "]": 4,
        ")": 5
    }
    if (s.length % 2 !== 0 || map[s[0]] > 2) {
        return false
    }
    let arr = []
    for(let i=0;i<s.length;i++){
        if(s[i] in map){
            arr.push(map[s[i]])
        }
    }

    var resetA = (a) => {
        if(a === 0){
            a = -1 //每一次遍历完a会加一，置a为0
        }else{
            a = a - 2
        }
        return a
    }

    var fun = (arr) => {
        for(let a=0;a<arr.length;a++){
            if((arr[a]+arr[a+1]) === 5 && arr[a] < arr[a+1] && a<arr.length-1){
                arr.splice(a,2)
                a = resetA(a) // 重置索引
            }
            if((arr[a]+arr[a-1]) === 5 && arr[a] > arr[a-1] && a>0){
                arr.splice(a-1,2)
                a = resetA(a)
            }
        }   
    }
    fun(arr)
    return arr.length === 0
};
```
