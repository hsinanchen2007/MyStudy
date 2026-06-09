### 解题思路
1、单词反转
2、数组排序

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
  const unique = [];
  const rev = words.map(word=>word.split('').reverse().join('')).sort();
  for(let i = 0; i < rev.length; i += 1){
    if(!rev[i+1]||rev[i+1].indexOf(rev[i])===-1){
      unique.push(rev[i]);
    }
  }
  const S = '#' + unique.join('#');
  return S.length;
};
```