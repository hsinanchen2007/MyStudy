咋一眼看上去，题目中的 next 指针有两种情况：

第一种，连接某个节点的左右孩子的 next 指针，比如图中的 `4 -> 5`

![559C5E26-2DE6-440C-8314-72F4C680D6A8.jpg](https://pic.leetcode-cn.com/be7013787b44d2f37246b5dcc2820dd60c01b3c84b81cdab65026a38759990dc-559C5E26-2DE6-440C-8314-72F4C680D6A8.jpg)

第二种，连接非左右孩子的 next 指针，比如上图中的 `5 -> 6`

但实际上，换个角度看，其实只有一种情况：

![E2810038-248A-4C4B-ACA0-003893B375F7.jpg](https://pic.leetcode-cn.com/65d62188b4e474b4f880345eedb22d0fc7d158b8dfb8de23f1c5091715a6943c-E2810038-248A-4C4B-ACA0-003893B375F7.jpg)

比如图中的 `2 -> 3`， `5 -> 6`，都可以看成是节点 `1` 的 **左子树的最右侧的路径** 与 **右子树的最左侧的路径** 一一相连的结果。

所以只要先创建一个方法，它能将给定节点的左右子树，按照上面的规则相连：

```javascript
  function link (node) {
    if (!node) return
    let l = node.left, r = node.right
    while (l) {
      l.next = r
      l = l.right
      r = r.left
    }
  }
```

然后对这棵树上的节点都应用一遍就OK了：

```javascript
var connect = function(root) {
  if (!root) return root
  link(root)
  connect(root.left)
  connect(root.right)
  return root
}
```




