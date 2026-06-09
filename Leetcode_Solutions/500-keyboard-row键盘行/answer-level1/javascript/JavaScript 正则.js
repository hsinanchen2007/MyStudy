三行 每行写一个表达式 然后匹配就好了。
```
var findWords = function(words) {
    var reg1 = /[asdfghjkl]+/i;
    var reg2 = /[qwertyuiop]+/i;
    var reg3 = /[zxcvbnm]+/i;

    for(var i=0;i<words.length;i++){
        if(words[i].replace(reg1, "").length==0||
        words[i].replace(reg2, "").length==0||
        words[i].replace(reg3, "").length==0){
            //...
        }
        else{
           words.splice(i, 1);
           i--;
        }
    }
    return words;
};
```
