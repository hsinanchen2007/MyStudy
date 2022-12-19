 * step 1：先根据字典序排序数组(可利用语言api自带实现)
 * step 2：定义Set保存单词的前缀，定义ResultWord作为返回结果
 * step 3：遍历数组，单个字符作为最原始的值保存到Set，一个一个字符添加组成单词的前缀(eg. h -> he -> hel -> hell -> hello)
 * step 4：最后取最大长度的单词，由于words已经按照字典升序排序，所以只要考虑长度
 * 
```
/**
 * 一行代码版本
 *
 * @param {string[]} words
 * @return {string}
 */
const longestWord = words => (WordsPrefixSet = new Set(), ResultWord = '', words.sort().forEach(w => w.length == 1 || WordsPrefixSet.has(w.substring(0, w.length - 1)) ? WordsPrefixSet.add(w) && ResultWord.length < w.length ? ResultWord = w : false : false), ResultWord)

```
