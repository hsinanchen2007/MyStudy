### 解题思路
此处撰写解题思路
两个数组先由小到大排序， 定义一个变量childNum来记录满足的孩子的数量
遍历饼干的数组，循环条件为满足的孩子数量不能超过孩子的总数量并且不超过g的长度，如果该饼干可以满足孩子，孩子数+1，进入下一次循环。 若不能满足，则直接进入下一次循环。
### 代码

```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
  g.sort((a, b) => a - b)
  s.sort((a, b) => a - b)
  let childNum = 0
  for(let i = 0; i<s.length && childNum<g.length; i++){
      if(s[i]>=g[childNum]){
          childNum++
      }
  }
  return childNum
};
```