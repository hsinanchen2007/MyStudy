### 解题思路
递归：先写出口，然后最终结果就是root的值拼接left结果和right结果
迭代：路径存在node上，当前节点的路径就是父节点的路径+自己的值，叶子节点取出结果

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
 * @return {string[]}
 */
//递归
var binaryTreePaths = function(root) {
    if(root == null) return []
    if(root.left == null && root.right == null) return [root.val+'']
    return [...binaryTreePaths(root.left).map(item => root.val+'->'+item),
            ...binaryTreePaths(root.right).map(item => root.val+'->'+item)]
};
//迭代（DFS）
var binaryTreePaths = function(root) {
    if(root == null) return []
    root.path = root.val+''
    const queue = [root],
    ret = [];
    while(queue.length>0){
        const node = queue.pop()
        if(node.left === null && node.right === null){
            ret.push(node.path)
        }
        if(node.left !== null){
            node.left.path = node.path+'->'+node.left.val
            queue.push(node.left)
        } 
        if(node.right !== null){
            node.right.path = node.path+'->'+node.right.val
            queue.push(node.right)
        } 
    }
    return ret
};
```