哝，本菜鸡只能这样子了：
```
var isPalindrome = function(x) {
    x = x.toString();
    for(var i = 0;i<x.length/2;i++){
        if(x[i]!=x[x.length-1-i]){
            return false;
        }
    }
    return true;
};
```

执行用时 :
276 ms
, 在所有 JavaScript 提交中击败了
97.20%
的用户

内存消耗 :
46.2 MB
, 在所有 JavaScript 提交中击败了
19.26%
的用户