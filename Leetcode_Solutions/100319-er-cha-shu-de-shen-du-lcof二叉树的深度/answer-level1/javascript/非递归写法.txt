### 解题思路
本质上是后序遍历，因为只有遍历完左右子树，才能比较深度
压入栈中的元素，多一个flag标志位，表示当前节点右子树是否已遍历

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
 * @return {number}
 */
var maxDepth = function(root) {
    if(!root) return 0
    let stack = []
    let cur = root
    let depth = 0
    while(stack.length || cur){
        while(cur){
            stack.push([cur,0])
            cur = cur.left
        }
        // 弹出栈顶元素，检查该节点右子树是否遍历完
        let [node,flag] = stack.pop()
        if(flag) {
            // 栈顶节点右子树已遍历完，要么是叶节点，要么是左右子树都遍历完的某个父节点
            // 比较栈的深度，如果为叶节点，则已经代表最大深度
            // length + 1 是因为栈顶弹出了一个元素
            depth = Math.max(stack.length+1, depth)
        }else{
            if(node.right){
                // 如果右子树存在，则遍历右子树，并将该节点 flag 置为 1 重新压回栈中
                stack.push([node, 1])
                cur = node.right
            }else{
                stack.push([node, 1])
                cur = null
            }
        }
    }
    return depth
};
```