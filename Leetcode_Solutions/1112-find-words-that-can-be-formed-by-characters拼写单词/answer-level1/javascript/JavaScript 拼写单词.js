思路：将字典和单词都拆成数组后排序，两个指针指向数组首部，相同则同时后移一位，不同则字典后移一位，最后验证
```javascript
var countCharacters = function(words, chars) {
    var dic = chars.split('').sort();
        var outLength = 0;
        for(var i = 0 ; i< words.length ; i++ ){
            var word = words[i].split('').sort();
            if(word.length>dic.length)
                continue;
            else{
                var wordI = 0 , dicI = 0 ;
                while( dicI < dic.length ){
                     dic[dicI]===word[wordI] ? (++dicI,++wordI) : ++dicI;
                }
            }
            ( wordI === word.length)?outLength+=word.length:true;
        }
         
        return outLength;
};
```