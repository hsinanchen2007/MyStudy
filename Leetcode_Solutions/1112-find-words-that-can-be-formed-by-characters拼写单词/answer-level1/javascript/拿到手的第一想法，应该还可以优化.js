### 解题思路
1.先遍历words，一个一个单词判断
2.把每个单词拆成一个个字母，然后判断chars里是否有这个字母，有的话就将它在chars里删掉
3.如果检测到有一个字母是chars没有的，就直接跳出当前循环
4.如果遍历完当前单词的所有字母了，它们都在chars里的话，就判断现在被处理过的chars的长度是不是等于原chars的长度减去当前单词的长度，是的话就说明这个单词是符合的，就把他push进result里
5.把result里的所有字符串转换成一个字符串，输出它的长度即为所求
### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function (words,chars){
    let result = []
    words.forEach(item =>{
        let nowChars = chars
        for(let i = 0;i<item.length;i++){
           const ci = nowChars.indexOf(item[i])
           if(ci >= 0){//如果chars里有这个字母，就把它从chars丢掉，
            // 如果其中有一个没有，就直接结束，下一个，如果都有，当遍历完了chars不为空，则把item加到result里
                nowChars = nowChars.substring(0,ci) + nowChars.substring(ci + 1,nowChars.length);
           }else{
               break
           }
        }
        if(nowChars.length === (chars.length -item.length)){
           result.push(item)
        }
    })  
    let count = result.join("")
    return count.length
}
```