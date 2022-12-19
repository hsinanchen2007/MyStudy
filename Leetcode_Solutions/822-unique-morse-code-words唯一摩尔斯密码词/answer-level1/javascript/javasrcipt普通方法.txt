```
var uniqueMorseRepresentations = function(words) {
    var base = "abcdefghijklmnopqrstuvwxyz";
    var text_code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    var resArr = []; //单词数组
    var wordCode = ""; //单词拼接

    for(var i =0;i<words.length;i++){
        wordCode = "";
        for(var j =0;j<words[i].length;j++){
            k = base.indexOf(words[i][j]);
            wordCode = wordCode.concat(text_code[k]);
        }
        if(resArr.indexOf(wordCode) == -1){
            resArr.push(wordCode)
        }
    }
    return resArr.length;
};
```
