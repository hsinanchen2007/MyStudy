首先计算数组中最短的字符串长度，然后循环对比

优化解：取第一个元素，然后依次与之后元素对比，如果不匹配，删除最后一个元素继续对比

```
var longestCommonPrefix = function (strs) {
    var sim = ""
    let min = NaN
    // if(strs.length==1){
    //     return strs[0]
    // }else if(strs.length<=0){
    //     return sim
    // }
    for(let s of strs){
        min = s.length>min?min:s.length
    }
    let prev = ""
    for(let i = 1;i<=min;i++){
        prev = strs[0].substr(0,i)
        for(let s of strs){
            if(prev!=s.substr(0,i)){
                return sim
            }
        }
        sim = prev
    }
    return sim
};
```
