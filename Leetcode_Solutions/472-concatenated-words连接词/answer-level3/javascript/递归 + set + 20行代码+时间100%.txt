- words按照长度从低向高排序
- 第一个单词长度最短肯定是不是结果
- 不是返回结果的单词  加入set中 认为是一个普通的单词
- 然后从第二个单词开始 每次取单词的一个字母加上单词中之前的字符串 判断set中是否存在
- 如果存在 并且到达单词末尾  则找到 
- 如果存在 但是未到达末尾  继续寻找 将起始字符串的索引加1
- 否则失败 将单词加入set中
```
var findAllConcatenatedWordsInADict = function (words) {
  let set = new Set();
  let res = [];
  let getWord = function (word, start) {
    for (let str = '', len = word.length - 1; start <= len; ++start) {
      str += word[start]
      if (set.has(str) && (start === len || getWord(word, start + 1))) {
        return true;
      }
    }
    return false;
  }
  words.sort((a, b) => a.length - b.length);
  set.add(words[0]);
  for (let i = 1, len = words.length; i < len; ++i) {
    if (getWord(words[i], 0)) {
      res.push(words[i])
    } else {
      set.add(words[i])
    }
  }
  return res;
};
```
