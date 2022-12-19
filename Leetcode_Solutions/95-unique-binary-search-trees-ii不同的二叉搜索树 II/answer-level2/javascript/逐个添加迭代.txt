### 解题思路
先造成n=2的可能结果；
f(n)的结果就是遍历f(n - 1)的结果，然后给每个二叉树添加n节点；
添加n节点只有两种可能：
1、n节点作为根节点，剩下的二叉树作为n节点的左子树；
2、n节点插入二叉树的根节点或任意右节点，作为其右节点，然后原右子树作为n节点的左子树。
（每次生成新结果需要复制一份新的二叉树）

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
    if (n === 0) return []
    if (n === 1) return [new TreeNode(1)]
    let res = [new TreeNode(1), new TreeNode(2)]
    res[0].right = new TreeNode(2)
    res[1].left = new TreeNode(1)
    let num = 3
    while (num <= n) {
        let cache = []
        res.forEach(root => {
            let newRoot = new TreeNode(num)
            newRoot.left = root
            cache.push(newRoot)
            let node = root
            while (node) {
                newN = new TreeNode(num)
                let newNode = new TreeNode(node.val)
                newNode.left = node.left
                newNode.right = newN
                newN.left = node.right
                let newRoot = node === root ? newNode : copyTree(root, newNode)
                cache.push(newRoot)
                node = node.right
            }
        })
        res = cache
        num++
    }
    return res

    function copyTree(root, target) {
        let res = new TreeNode(root.val), parent = res
        while (root.right) {
            let node = new TreeNode(root.right.val)
            if (root.right.val === target.val) {
                parent.right = target
                parent.left = root.left
                break
            }
            parent.right = node
            parent.left = root.left
            parent = node
            root = root.right
        }
        return  res
    }
};
```