### 解题思路
1. 对数组进行字典排序
2. 对数组中的字符串进行遍历判断是否是其他字符串拼接后的字符串
3. 如果是拼接字符串，则去掉相同部分的前缀，继续递归判断是否是拼接字符串
4. 递归终止条件为:去掉了相同部分前缀的字符串为空字符串
### 代码

```javascript
var longestWord = function(words) {
    //先对words进行字典序排序
    let sortWords = words.sort();
    let currentMaxLengthStr = '';
    for (let i = 0; i < sortWords.length; i++) {
        let isComb = isCombined(words[i], 0, sortWords);
        if (isComb && currentMaxLengthStr.length < words[i].length) {
            currentMaxLengthStr = words[i];
        }
    }
    return currentMaxLengthStr;
    
};

//如果字符串找到了子字符串，则查询下一个下标之后是否有子字符串
var isCombined = function(word, indexFrom, words) {
    if (indexFrom >= word.length) {
        return true;
    }
    //遍历是否有子字符串
    for (let i = 0; i < words.length; i++) {
        let wordAtIndex = words[i];
        if (word === wordAtIndex) continue;
        if (word.substr(indexFrom).indexOf(wordAtIndex) === 0 && isCombined(word, indexFrom + wordAtIndex.length, words)) {
            return true;
        }
    }
    return false;
}
```