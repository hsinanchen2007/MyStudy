![image.png](https://pic.leetcode-cn.com/b1ae8523c3df88aa7aee00e2bced22c94bcc2e541d739e2932268f2160cb6b23-image.png)

### 解题思路
```js
  依次遍历 words，如果一个 word 中的所有字符串在 chars 中都不重复，那么即为掌握，
  统计长度即可。
  
  统计字符串是否重复的方式：每次判断一个单词的时候，copy 出一份 chars，每个字符依次
  查找，查找到就把这个字符在这份 chars 中删除，防止重复使用，一旦某个字符没有找到，那么
  为不可掌握。
```

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */

var countCharacters = function(words, chars) {
  let ans = 0;
  
  for (let word of words) {
    let flag = true, copyChars = chars;
    
    for (let i = 0; i < word.length; i++) {
      let c = word.charAt(i);
      let index = copyChars.indexOf( c );
      
      if (index === -1) {
        flag = false;
        break;
      }
      
      copyChars = copyChars.slice(0, index).concat( copyChars.slice(index + 1) );
    }
    
    if (flag === true) ans += word.length;
  }
  
  return ans;
};
```