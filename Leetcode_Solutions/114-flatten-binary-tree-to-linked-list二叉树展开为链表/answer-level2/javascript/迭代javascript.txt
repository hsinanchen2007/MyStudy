### 思路
do
root ---(有右子树)---> 右子树入栈
            |---(有左子树)---> 将左子树变为新树的右子树，左子树置空，root=root.right
            |---(没有左子树)---> 栈pop一个元素 成为root的右子树， root=root.right
while(root为叶子节点且栈空，退出循环)

### 代码
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    if(!root) return null
    const stack = []
    while(root.left || root.right || stack.length>0){
        if(root.right) stack.push(root.right)
        if(root.left){
            root.right = root.left
            root.left = null
            
        }else{
            root.right = stack.pop()
        }
        root = root.right
    }
};
```
