## 基本思路

如果不考虑右边界的话这道题很简单，因为左边界与叶子节点的访问顺序正好和先序遍历是一样的，大致上只要这样就可以了：

```javascript
function preOrderTraversal(root) {
  if (root) {
    if (/*还没有访问过叶节点 or 当前节点是叶节点 */) { result.push(root.val) }
    preOrderTraversal(root.left)
    preOrderTraversal(root.right)
  }
}
```

那右边界怎么处理呢？其实只要将先序遍历中的左右子树访问顺序换一下，就可以用同样的方法得到右边界了。

但是如果我们这样分开处理，会有一个很麻烦的问题就是如何处理重复的路径，这里我们采用迭代器的思路解决这个问题。具体思路就是从根节点开始，一边以左子树优先进行先序遍历，一边以右子树优先进行先序遍历，每次遍历一个节点并进行对比，左子树遍历负责记录左边界与叶边界，右子树遍历负责右边界，如果遍历过程中节点相同，表示路径重合了，则记录在右子树中。

另外还有一些边界情况需要处理，比如根节点有无左右子树的情况，这里就不在啰嗦了，直接看代码吧。

## 代码

```javascript
var boundaryOfBinaryTree = function(root) {
    if (root === null) return []
  
    // 是否有左右边界
    const hasLeft = root.left !== null
    const hasRight = root.right !== null

    const leftBoundary = []
    const leafs = []
    const rightBoundary = []
    
    // 先序遍历迭代器
    const gleft = preOrderTraversal(root)
    const gright = preOrderTraversalR(root)
    
    let p = gleft.next()
    let q = gright.next()
    
    // 先序遍历是否已经访问到叶节点
    let leftComplete = false
    let rightComplete = false

    while(!p.done) {
      // 根节点总把它作为左边界
      if (p.value === root) {
          leftBoundary.push(root.val)
      } else {
        // 正向遍历访问到了叶节点，此时意味着左边界已经全部访问过
        // 同时将叶节点放入叶节点数组中
        if (isLeaf(p.value)) {
          leftComplete = true
          leafs.push(p.value.val)
        }
        // 同理，设置逆向遍历的flag
        // 叶节点已经在正向遍历里处理过了，所以这里可以忽略
        if (isLeaf(q.value)) {
          rightComplete = true
        }
        // 处理左边界，在左边界未访问完且有左子树的情况下才向左边界中记录节点
        // 同时，因为左右遍历是同时迭代的，可能出现路径重合的情况
        // 这种情况下根据题意在右边界中记录
        if (!leftComplete && hasLeft && (!hasRight || p.value !== q.value)) {
          leftBoundary.push(p.value.val)
        }
        // 右边界的处理同上
        if (!rightComplete && hasRight) {
          rightBoundary.unshift(q.value.val)
        }
      }
  
      p = gleft.next()
      q = gright.next()
    }
    
    return [...leftBoundary, ...leafs, ...rightBoundary]
    
    // 先序遍历迭代器
    function *preOrderTraversal (root) {
      if (root) {
        yield root
        yield *preOrderTraversal(root.left)
        yield *preOrderTraversal(root.right)
      }
    }
    
    // 右子树优先的先序遍历
    function *preOrderTraversalR (root) {
      if (root) {
        yield root
        yield *preOrderTraversalR(root.right)
        yield *preOrderTraversalR(root.left)
      }
    }
    
    // 判断是否叶节点
    function isLeaf(node) {
        return node && node.left === null && node.right === null
    }
  };

```