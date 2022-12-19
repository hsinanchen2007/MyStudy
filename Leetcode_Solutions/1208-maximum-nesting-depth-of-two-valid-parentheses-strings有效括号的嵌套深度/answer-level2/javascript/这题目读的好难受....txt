### 解题思路
这个题目意思不太好读啊，反复看题目和例子，如果按要求题目意思去解，要维护两个数组，然后匹配求解
如果单纯为了解答案，这个没有严格的括号匹配,右括号的dep与左括号是相连的,匹配到'(',dep++,匹配到')'，dep--就完事了

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
  let dep=0
  return seq.split('').map(item=>item==='(' ? dep++ % 2 : --dep % 2)
};
```