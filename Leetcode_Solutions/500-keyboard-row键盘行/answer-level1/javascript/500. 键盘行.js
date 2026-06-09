## 题目剖析

### 题目描述
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。

键盘上其实就 ``26`` 个英文字母，「返回键盘上同一行的字母打印出来的单词」无疑在明示我们用 ``HashMap`` 来解决这道题。

### 解题思路

1. 对同一行的字母做映射，比如说第一行的所有字母映射到数字 ``1`` 并以此类推；然后对数组进行遍历，符合要求则返回（这里要注意大小写的问题）
2. 用 ``正则`` 也可以解决这道题，只要判断该单词是否符合某一行的组合就行了

## 示例代码

### ``HashMap`` 解法

```javascript
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    const map = new Map([
      ['q',1],['w',1],['e',1],['r',1],['t',1],['y',1],['u',1],['i',1],['o',1],['p',1],
      ['a',2],['s',2],['d',2],['f',2],['g',2],['h',2],['j',2],['k',2],['l',2],
      ['z',3],['x',3],['c',3],['v',3],['b',3],['n',3],['m',3]
    ]), ans = []
    for (const word of words) {
        const target = map.get(word[0].toLowerCase())
        const canBeAdded = word.split('').every((item) => {
            return map.get(item.toLowerCase()) === target
        })
        if (canBeAdded) {
            ans.push(word)
        }
    }
    return ans
};
```

### ``正则`` 解法

```javascript
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    return words.filter((word) => /^[qwertyuiop]+$|^[asdfghjkl]+$|^[zxcvbnm]+$/.test(word.toLowerCase()))
};
```