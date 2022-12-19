第一：如果将start、end中的‘X’全部去掉得到的newStart 和 newEnd相等才有可能转换成功。
第二：如果start中'R'的左边'X'的个数超过在end中对应位置的'R'的左边'X'的个数，则不能转换成功，因为start中的'R'只能向右移动，右边的'X'只能增加不能减少
第三：如果end中'L'的左边'X'的个数超过在start中对应位置的'L'的左边'X'的个数，则不能转换成功，因为start中的'L'只能向左移动，左边的'X'只能减少不能增加
```
var canTransform = function(start, end) {
    let i=0;
    let j=0;
    while(i<start.length && j < end.length){
        while(start[i] === 'X' && i < start.length) i++
        while(end[j] === 'X' && j < end.length) j++
        if(start[i] !== end[j]) return false
        if(start[i] === 'R' && end[j] === start[i]){
            if(i > j) return false
        }
        if(start[i] === 'L' && end[j] === start[i]){
            if(i < j) return false
        }
        i++
        j++
    }
    return true
};
```

