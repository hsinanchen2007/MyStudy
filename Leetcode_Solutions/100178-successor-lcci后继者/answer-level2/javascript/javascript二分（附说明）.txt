### 解题思路
第一个想法是中序遍历，这样时间复杂度是O(n),因为是二叉查找树，所以更快一些的方法是用二分查找
对于每棵树的根节点
1. 如果p大于根节点，那么解一定在右子树
2. 如果p等于根节点，在右子树中查找最小节点。最小节点就是解，找不到返回 null。
3. 如果p小于根节点，那么解可能在左子树，如果不在，根节点就是解。

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
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @return {TreeNode}
 */
var inorderSuccessor = function (root, p) {
    if(!root) return null
    if(p.val>root.val) return inorderSuccessor(root.right,p)  
    else if(p.val===root.val){
        let node=root.right
        while(node&&node.left) node=node.left
        return node
    }
    else{
       return inorderSuccessor(root.left,p)||root
    }
};
```