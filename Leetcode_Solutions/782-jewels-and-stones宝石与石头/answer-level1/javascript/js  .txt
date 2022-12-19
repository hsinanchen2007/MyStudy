方法1：正则
```
通过字符串方法match匹配，然后返回匹配到的数组的长度（注意match返回值可能为null）
var numJewelsInStones = function(J, S) {
    let reg = new RegExp('['+J+']','g')
    let s = S.match(reg)
    return s ? s.length : 0
};
```
方法二：哈希表/数组
```
循环S，如果当前元素存在于J中就把宝石的数量+1
var numJewelsInStones = function (J, S) {
    J = J.split('')
    let index = 0
    for(let s of S){
        if(J.includes(s))
            index++
    }
    return index
};
```
