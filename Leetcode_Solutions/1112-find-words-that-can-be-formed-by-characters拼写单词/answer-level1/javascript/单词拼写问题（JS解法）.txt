### 解题思路
每次遍历words中的单词都复制一份chars，遍历每个单词的每个字母与chars副本中的逐一比对，一旦遇到chars中找不到的字母，终止本次循环开始遍历下一个单词。如果可以找到，则单词中找到一个字母就在chars副本中删除一个对应的字母。最后判断是否已经遍历完整个单词，如果完成则在最后加上这个单词的长度。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let wordsLen = 0;
    for(let i = 0; i < words.length; i++){ // 单词列表遍历每个单词
        if(words[i].length > chars.length){  // 如果单词的长度比chars长度更长，不可能拼出单词，跳过本次循环
            continue;
        }
        let flag = false;  // 单词遍历是否完整的标记，true: 遍历完成，fasle：未完成
        let checkChars = chars.split(""); // 复制一份chars，并将字符串切分为数组
        for(let j = 0; j < words[i].length; j++){  // 单词中遍历每个字母
            let itemIndex = checkChars.indexOf(words[i][j]);  // 在chars副本中寻找字母的下标，找不到返回值为-1
            if (itemIndex == -1){ // 找不到对应字母，打断本次循环，无需再考虑这个单词
                break;
            }
            checkChars.splice(itemIndex, 1); // 找到对应的字母，删除chars副本中的对应字母，防止重复使用
            if(j == words[i].length - 1){ // 如果单词的所有字母遍历完成，这个单词可以用chars中的字母拼出来，将标记设为true
                flag = true;
            }
        }
        if (flag){ // 标记为true的单词，在返回值中加入它的长度
            wordsLen += words[i].length;
        }
    }
    
    return wordsLen;
};
```