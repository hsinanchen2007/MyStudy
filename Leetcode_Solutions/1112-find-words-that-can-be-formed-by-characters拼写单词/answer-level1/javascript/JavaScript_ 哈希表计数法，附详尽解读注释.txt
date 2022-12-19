首先，需要考虑下，如何才能**构成单词**：
1. 单词里具备的字母需在字母表中也具备。
2. 字母表中每个字母的个数应该满足单词中每个字母出现的个数，换句话说就是要“大于等于”。

那么，有没有什么现成的数据结构，即可以分辨出字母(`key`)，又能保存这个字母出现的次数(`value`)，还可以快速判断出是否具有这个字母呢？

显而易见，**哈希表**(`Map`)满足这一结构要求。

在ES6中，Map这一数据结构已经被实现了，所以直接使用就行。

解决这个核心问题，再来回顾下其他的问题。

- 如何构造出字母表自身的哈希表？很简单，直接遍历这个字母表，对每个字母出现的频率进行统计就行了。
- 词汇表是个字符串数组，如何统计其中每个单词中的字母出现频率？ 显而易见，需要双重循环就可实现，外层循环遍历每个单词，内层循环遍历单词中的每个字母，顺带统计其出现频率。
- 在哪个时机对`字母表Map`和`单词Map`进行“构成单词”的判断呢？很显然，这个时机必须在`字母Map`和`单词Map`都已知的情况下，才能正常进行。

现在已经理清了关键脉络，直接附上具体代码，结合代码注释，可以更好地理解脉络关键。

```
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
     // 用于保存长度之和
     let size = 0;
     // 字母Map，用于存放每个字母的出现频率
     let charMap = new Map();

     for(let char of chars) {
        // 遍历字母表，统计其中每个字母出现的频率
        charMap.set(char, (charMap.has(char) ? charMap.get(char) + 1 : 1));
     }

     // 双重循环，外层循环遍历单词数组中的每个单词
     for(let word of words) {
         // 单词Map，用于存放单词中每个字母的出现频率
         let wordMap = new Map();

         // 内层循环
         for(let char of word) {
             // 统计字符串（单词）中每个字母出现的频率
             wordMap.set(char, (wordMap.has(char) ? wordMap.get(char) + 1 : 1));
         }

         // 是否满足拼写
         let enough = true;

         // 遍历待匹配单词的每个字母
         for(let char of word) {
             // 判断 字母表中的字母是否足够拼写单词 或者 字母表中是否有该字母
            if(wordMap.get(char) > charMap.get(char) || charMap.get(char) === undefined) {
                enough = false;
                break;
            }
         }
         if(enough) {
             // 累加可拼写的单词长度
             size += word.length;
         }
     }

     // 返回单词长度
     return  size;
};
```


