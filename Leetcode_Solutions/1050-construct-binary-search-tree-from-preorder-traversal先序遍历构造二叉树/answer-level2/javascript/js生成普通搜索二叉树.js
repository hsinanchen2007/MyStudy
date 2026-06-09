### 解题思路
通过递归的思想，生成二叉树

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
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    var tree = new TreeNode();
    preorder.map(i => {
        tree.insert(i);
    })

    return tree.root;

    function TreeNode() {
        this.root = null;
        
        // 生成二叉树
        this.insert = function(val) {
            var newNode = new Node(val);

            if (this.root === null) {
                this.root = newNode;
            } else {
                insertNode(this.root, newNode);
            }
        }

        // 二叉树节点
        function Node(val) {
            this.val = val;
            this.left = null;
            this.right = null;
        }

        // 小于当前节点val，插入到left
        // 大于或等于当前节点val，插入到right
        function insertNode(node, newNode) {
            if (newNode.val < node.val) {
                if (node.left === null) {
                    node.left = newNode;
                } else {
                    insertNode(node.left, newNode);
                }
            } else {
                if (node.right === null) {
                    node.right = newNode;
                } else {
                    insertNode(node.right, newNode);
                }
            }
        }
    }
    
};
```