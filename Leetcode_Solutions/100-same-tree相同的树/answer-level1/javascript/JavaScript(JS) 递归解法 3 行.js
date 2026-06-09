### 解题思路
对于每个节点都可以采取一样的操作，因而使用递归

### 代码

```javascript
var isSameTree = function (p, q) {
    if (!p || !q) return p === q
    if (p.val !== q.val) return false
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
};
```