我们假设取某个数作为顶点，有 n 个数小于它，m 个数大于它。
显然，它的左子树的集合和 `generateTree(n)`完全一致。
那它的右子树呢？右子树和`generateTree(m)`的结构完全一致，但每个节点的值都比`generateTree(m)`要大一个常数。
举个例子，如果我们已知由`[1,2,3]`组成的所有二叉搜索树，那么在将每个搜索树的所有节点都 +1，就可以得到`[2,3,4]`组成的二叉搜索树集合。

所以我们可以抽象出一个更通用的函数：`generateTreeWithDelta(n, delta)`。
它可以返回由1到n组成的所有二叉搜索树，且在每个节点原有的值上加上`delta`。
这样就可以递归调用了。


```javascript
var generateTrees = function(n) {
  if (n === 0) return []
  return generateTreeWithDelta(n, 0)

  function generateTreeWithDelta (n, delta)
    if (n === 0) return [null]
    if (n === 1) return [new TreeNode(n + delta)]
    const result = []
    let node = null
    for (let i = 1; i <= n; i++) {
      for (const ln of generateTreeWithDelta(i - 1, delta)) {
        for (const rn of generateTreeWithDelta(n - i, delta + i)) {
          node = new TreeNode(i + delta)    
          node.left = ln
          node.right = rn
          result.push(node)
        }
      }
    }
    return result
  }
};

```