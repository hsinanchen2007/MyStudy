字符串 replace + length 比较，和 indexOf 方式稍有不同
```javascript []
var countCharacters = function(words, chars) {
    var res = 0;
    for(let i in words){
        var hasWord = true;
        var target = chars;
        for(let j in words[i]){
            target = target.replace(words[i][j], '');
            if(target.length > chars.length-j-1){
                hasWord=false;
                break;
            }
        }
        if(hasWord){
            res += words[i].length;
        }
    }
    return res;
};
```
