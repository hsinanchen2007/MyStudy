```
/*
    解题思路：
            1. 全是大写，利用toUpperCase函数，将原字符串转换为大写，再与原字符串比较，相同则true
            2. 全是小写，利用toLowerCase函数，将原字符串转换为小写，再与原字符串比较，相同则true
            3. 首字母大写，判断后面的是否全是小写，全是小写则true
*/
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    if(word.length === 0) return false;
    if(word.length === 1) return true;
    var uper = word.toUpperCase();
    var lower = word.toLowerCase();
    if(uper === word){
        return true;
    }else if(lower === word){
        return true;
    }
    if(word[0]<='Z'&&word[0]>='A'){
        var newWord = word.slice(1);
        if(newWord === newWord.toLowerCase()){
            return true;
        }
    }
    return false;
};
```
