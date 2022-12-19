
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * 递归
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function (root, key) {
    if (root === null) {
        return null;
    }

    // 当前节点是要删除的节点
    if (root.val === key) {
        // 1:节点是叶子，删除该节点
        if (root.left === null && root.right === null) {
            root = null;
        }
        // 2:节点只有一边子节点，用子节点代替节点
        else if (root.left === null || root.right === null) {
            root = root.left === null ? root.right : root.left;
        }
        else {
            // 场景3:节点有两边节点，找到后置节点和当前节点交换
            let successor = root.right;
            while (successor.left !== null) {
                successor = successor.left;
            }
            root.val = successor.val;
            root.right = deleteNode(root.right, root.val);
        }

    }
    // 在右子树删除
    else if (key > root.val) {
        root.right = deleteNode(root.right, key);
    }
    // 在左子树删除
    else if (key < root.val) {
        root.left = deleteNode(root.left, key);
    }

    return root;
};
```