### 解题思路
利用深度优先遍历的方式进行
递归是深度遍历比较好的方式
注意点： 遍历每个节点的时候，找到当前节点的level，并动态在quene中添加数组

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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(root == null || root ==[]){return []}
    let quene = []
    insertOrder(root, 0 , quene)
    return quene
};
var insertOrder = function(root, level, quene){
    if(root == null) {return}

    if(quene.length < level + 1){
        quene.push([])
    }
    quene[level].push(root.val)

    insertOrder(root.left , level + 1 , quene)
    insertOrder(root.right , level + 1 , quene)

    return quene
}


```