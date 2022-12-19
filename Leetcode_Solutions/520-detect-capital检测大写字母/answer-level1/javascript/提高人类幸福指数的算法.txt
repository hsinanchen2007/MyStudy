**思路：**
1. 先判断全部大写 
2. 从第二个字母开始循环，有大写字母就返回false 
3. 循环到最后返回true
```
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    if(word.toUpperCase() === word) return true; // 全部大写
    for(let i = 1; i < word.length; i++) {
        // word[i].charCodeAt(0) >= 65 && word[i].charCodeAt(0) <= 90 这个是大写字母
        if(word[i].charCodeAt(0) <= 90) { // 一个单词只有大小写字母 判断小于90就好了
            return false;
        }
    }
    return true;
};
```
