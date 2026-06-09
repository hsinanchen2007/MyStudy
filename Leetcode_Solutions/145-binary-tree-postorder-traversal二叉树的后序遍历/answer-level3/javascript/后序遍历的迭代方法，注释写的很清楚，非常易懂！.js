### 解题思路
二叉树遍历，第一次压入栈的时候访问元素为前序遍历，第二次弹出元素时为第二次访问该元素为中序遍历，后序遍历应该最后第三次访问该元素，因此设置一个标志位，当前元素是否已遍历完右子树

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
 * @return {number[]}
 */
var postorderTraversal = function(root) {
    if(!root) return []
    let ans = []
    let stack = []
    // 当前遍历节点
    let cur = root
    while(stack.length!==0  || cur!== null){
        // 遍历左子树，压入栈中
        while(cur){  
            stack.push([cur,0])
            cur = cur.left
        }
        let [node, flag] = stack.pop()
        if(!flag){
            // 如果当前没有遍历过右子树
            // 重新压回栈中，并遍历右子树
            stack.push([node, 1])
            cur = node.right
        }else{
            // flag 为 1，则第三次访问到该节点，后序遍历输出
            ans.push(node.val)
        }
    } 
    return ans
};
```