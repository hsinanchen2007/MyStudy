执行用时 :88 ms, 在所有 JavaScript 提交中击败了83.33%的用户
内存消耗 :37.4 MB, 在所有 JavaScript 提交中击败了100.00%的用户
判断三种情况即可
```javascript []
var canTransform = function(start, end) {
    start=start.split('')
    end=end.split('')
    let i=0,
        j=0
    while (i<start.length&&j<end.length){
        while (start[i]=='X'&&i<start.length){
            i++
        }
        while (end[j]=='X'&&j<end.length){
            j++
        }
        //LR不能互相穿过
        if(start[i]!=end[j]){
            return false
        }
        //R只能右移
        if(start[i]=='R'&&end[j]=='R'){
            if(i>j){
                return false
            }
        }
        //L只能左移
        if(start[i]=='L'&&end[j]=='L'){
            if(i<j){
                return false
            }
        }
        i++
        j++
    }
    return true
};
```


