###### 左起寻找第一个lastIndexOf，在该区间内找所包含的lastIndexOf
```
/**
 * @param {string} S
 * @return {number[]}
 */
// 贪心算法 时间O(N) 空间O(N)
var partitionLabels = function(S) {
    let res = []
    for(let i = 0,len = S.length; i < len;){
        if(S.lastIndexOf(S[i]) === i){
            res.push(1)
            i++
        // }else if(S.lastIndexOf(S[i]) === S.length-1){
        //     res.push(S.length)
        //     i++
        }else{
            let maxIndex = S.lastIndexOf(S[i])
            for(let j = i+1; j < maxIndex; j++) {
                maxIndex = S.lastIndexOf(S[j]) > maxIndex ? S.lastIndexOf(S[j]) : maxIndex
            }
            res.push(maxIndex-i+1)
            i = maxIndex + 1
        }
    }
    return res
};
```
时间为O(N)是因为循环中，是因为外层循环次数加内层刚好为i的变化；
如果理解有误，还请大家帮助纠正，Thanks♪(･ω･)ﾉ