```
// 思路
/**
 * 1.统计规定字符的所有序号组成一个参照数组
 * 2.将目标数组的每个字母序号与其比较得出最小值
 * 3.将其推入新数组
 * 
 **/
var S = 'loveleetcode'
var C = 'e'
var s = S.split('')
// 参照数组
var arrRefer = []
for(var i=0; i<S.length; i++){
    if(s[i] == C){
        arrRefer.push(i)
    }
}
console.log('参照数组--',arrRefer)
// 目的数组
// 与参照数组中每个数都减一遍，取最小值
// 计算目的数组最小值推入结果数组
var arrTarget = []
for(var i=0; i<s.length; i++){
    var min = Math.abs(i - arrRefer[0])
    for(var j=0; j<arrRefer.length; j++){
        if(min > Math.abs(i - arrRefer[j])){
            min = Math.abs(i - arrRefer[j])
        }
    }
    arrTarget.push(min)
}
console.log('结果数组--',arrTarget)
```
1. 用时:100ms
2. 内存:35.2MB