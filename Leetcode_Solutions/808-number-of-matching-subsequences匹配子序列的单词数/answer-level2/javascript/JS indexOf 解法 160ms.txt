### 解题思路
按字母检索是否存在，不存在则立即返回false，存在则从下一个下标开始检索下一个字母。

### 代码

```javascript
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(S, words) {

    let isSubsequence = function(s, word) {
      let ix = -1;
      for (let i = 0; i < word.length; i++) {
        ix = s.indexOf(word[i], ix + 1);
        if (ix == -1) return false;
      }
      return true;
    };

    let count = 0;
    words.forEach((val) => {
      if (isSubsequence(S, val)) {
        count++;;
      }
    });

    return count;
  };
```