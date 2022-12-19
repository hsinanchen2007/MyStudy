### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    var res = 0;
    //遍历单词表
    words.forEach((item) => {
        var hashMap = [];
        //记录单词表哈希值
        for(var i = 0; i < chars.length; i++){
            hashMap[chars.charCodeAt(i)] = hashMap[chars.charCodeAt(i)] === undefined ? 1 : hashMap[chars.charCodeAt(i)]+1;
        }
        //遍历单词字母
        for(var j = 0; j < item.length; j++){
            if(!hashMap[item.charCodeAt(j)]) return;
            hashMap[item.charCodeAt(j)]--;
        }
        res += item.length;
    })
    return res;
};
```