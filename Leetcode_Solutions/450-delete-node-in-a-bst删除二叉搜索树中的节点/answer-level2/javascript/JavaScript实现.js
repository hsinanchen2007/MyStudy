### 解题思路
此处撰写解题思路

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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    if(root == null){
        return root;
    }
    if(key == root.val){
        // 如果该节点的左子树为空，返回该节点的右子树
        if(root.left == null){
            return root.right;
        } else if(root.right == null){
            return root.left;
        } else {
            let node = root.right;
            while(node.left != null){
                node = node.left;
            }
            node.left = root.left;
            return root.right;
        }
        // key 比root大，则从右子树中删除 key 节点
    } else if(key > root.val) {
        root.right = deleteNode(root.right,key);
    } else {
        root.left = deleteNode(root.left,key);
    }
    return root;
}
```