### 解题思路
中序遍历，先要将最左边的节点全部加入栈中，然后逐个pop出来
核心思想注意，将右子树重置为root，进行下一步的循环。

两个while嵌套，中间的就是继续存放子树的节点

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
var inorderTraversal = function(root) {
    let arr = []
    let stackArr = []
    while(root!=null || stackArr.length!=0){

        while(root!=null){
            stackArr.push(root)
            root = root.left
        }
        root = stackArr.pop()
        arr.push(root.val)
        root = root.right
    }
    return arr
};
```