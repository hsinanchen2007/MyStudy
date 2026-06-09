
可能是我第一个提交的原因，还有优化的空间
思路
1.统计数据中各元素出现的次数
2.统计次数值有没相等的
3.默认为true 当，出现次数相同时及为false
```
var uniqueOccurrences = function(arr) {
    let c = {}
    let e = {}
    let s =true
    for(let i =0;i<arr.length;i++){
        if(!c[arr[i]]){
            c[arr[i]] =1
        }else{
            c[arr[i]] =c[arr[i]] + 1
        }
    }
    for( let j in c){
        if(!e[c[j]]){
            e[c[j]] = true       
        }else{
            s =false
            e[c[j]] = false
        } 
    }
    return s
    
};
```

