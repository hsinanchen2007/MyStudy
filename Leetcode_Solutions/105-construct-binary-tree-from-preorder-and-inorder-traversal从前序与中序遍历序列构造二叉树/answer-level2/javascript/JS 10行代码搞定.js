### 解题思路
此处撰写解题思路
由前序遍历可知preorder数组中第一个数一定是root并弹出，根据root值在inorder所在位置可将inorder划分为左子树、右子树两部分。
按照相同的思路左右子树的根结点继续在preorder里面查找（队列先进先出）
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
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    return help(inorder)
    function help(inorder) {
        if (!inorder|| !inorder.length) return null
        let top = preorder.shift(), p = inorder.indexOf(top)
        let root = new TreeNode(top)
        root.left = help(inorder.slice(0, p))
        root.right = help(inorder.slice(p+1))
        return root
    }
    
};
```