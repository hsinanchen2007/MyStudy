### 解题思路
一个res数组存结果，一个tempList数组存路径。
当一个节点 没有左&&没有右 孩子的时候就返回当前路径，用join方法拼接成字符串存在结果当中。

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

var binaryTreePaths = function(root) {
    var res = []
    var tempList = []
    function loop (root){
        if(!root)return
        tempList.push(root.val)
        if(root.left){loop(root.left)}
        if(root.right){loop(root.right)}
        if(!root.left && !root.right){
            res.push(tempList.join("->"))
        }
        tempList.pop()
    }
    loop(root);
    return res
};
```