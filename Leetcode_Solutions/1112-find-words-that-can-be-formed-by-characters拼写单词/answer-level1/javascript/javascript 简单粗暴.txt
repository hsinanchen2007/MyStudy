### 解题思路
简单粗暴法：给定一个变量存字符结果(str)，先遍历单词数组，用临时变量存储给定字符（var tmp = chars），给定临时结果字符串（tmpS），判断单词长度是否比给定字符长度长，如果长就直接进行下一个单词对比，如果不长，遍历这个单词所有字符，若临时变量找到字符，给临时变量删除这个字符并且tmpS += 遍历的字符，若找不到，tmpS = ''，退出循环，str += tmpS，最后返回str的长度

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    var str = ''
    for(var i = 0; i < words.length; i++) {
        var word = words[i]
        var tmpS = ''
        var tmp = chars 
        if(word.length > chars.length) continue
        for(var j = 0; j < word.length; j++) {                     
            if(tmp.indexOf(word[j]) != -1) {                 
                tmp = tmp.replace(word[j], '')  
                tmpS += word[j]            
            } else {
                tmpS = ''
                break
            }
        }
        str += tmpS
    }
    return str.length    
};

```