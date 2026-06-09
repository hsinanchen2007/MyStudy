写了两天DFS,也稍微有了点心得,分享一下简单的代码吧
```
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  const arr = []
  function dfs(str, left, right) {
    //终止条件
    if (right > left || left > n) return
    //得到解之后添加进数组并返回
    if (right === n) {
      arr.push(str)
      return
    }
    //分别遍历左右子树
    dfs(str + '(', left+1, right)
    dfs(str + ')', left, right+1)
  }
  //开始时为空字符
  dfs('', 0, 0)
  return arr
};
```