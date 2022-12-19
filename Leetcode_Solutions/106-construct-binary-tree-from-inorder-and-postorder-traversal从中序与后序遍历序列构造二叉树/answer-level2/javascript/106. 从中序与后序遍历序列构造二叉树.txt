#### 二叉树
+ [二叉树的前、中、后序遍历 - 解法大全](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/demos/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%89%E5%BA%8F%E9%81%8D%E5%8E%86.md)
#### 解法一：递归
+ [思路同 105. 从前序与中序遍历序列构造二叉树 - 解法一](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou--6/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    if(!inorder.length) return null
    let n = postorder.length
    let tmp = postorder[n-1],mid = inorder.indexOf(tmp)
    let root = new TreeNode(tmp)
    root.left = buildTree(inorder.slice(0,mid),postorder.slice(0,mid))
    root.right = buildTree(inorder.slice(mid + 1),postorder.slice(mid,n-1))
    return root
};
```
#### 解法二：递归简便版
+ [思路同 105. 从前序与中序遍历序列构造二叉树 - 解法二](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou--6/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    let build = (inorder) => {
        if(!inorder.length) return null
        let tmp = postorder.pop(),mid = inorder.indexOf(tmp)
        let root = new TreeNode(tmp)
        root.right = build(inorder.slice(mid + 1))
        root.left = build(inorder.slice(0,mid))
        return root
    }
    return build(inorder)
};
```
#### 解法三：参考解法
+ [思路同 105. 从前序与中序遍历序列构造二叉树 - 解法三](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou--6/)
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    let p = i = postorder.length - 1;
    let build = (stop) => {
        if(inorder[i] != stop) {
            let root = new TreeNode(postorder[p--])
            root.right = build(root.val)
            i--
            root.left = build(stop)
            return root
        }
        return null
    }
    return build()
};
```