可以使用**递归**：

- 1x1 为有效，例如`[""]`和`["a"]`；
- 第一行和第一列不相同为无效；
- 第一行和第一列若相同，检查子方块是否有效。


```javascript
var validWordSquare = function(words) {
  // 1x1 是有效方块
  if(words.length === 1 && words[0] === "") return true;
  if(words.length === 1 && words[0].length === 1) return true;
  
  // 第一行不等于第一列 不是有效方块
  if(words.map(x => x[0]).join('') !== words[0]) return false;
  
  // 切除第一行和第一列
  words = words.slice(1).map(x => x.slice(1));
  
  // 递归
  return validWordSquare(words);
};
```
