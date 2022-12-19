### 解题思路
此处撰写解题思路

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
// 方法一 迭代
var levelOrder = function(root) {
    if(!root) return []
    var res = []
    var queue = [root]
    root.depth = 0
    while(queue.length){
        var node = queue.shift()
        var depth = node.depth
        if(!res[depth]){
            res[depth] = [node.val]
        }else{
            res[depth].push(node.val)
        }
        var left = node.left
        var right = node.right
        if(left) {
            left.depth = depth + 1
            queue.push(left)
        }
        if(right){
            right.depth = depth + 1
            queue.push(right)
        }   
    }
    return res
};
// 方法2 递归
var levelOrder = function(root) {
    if(!root) return []
    var res = []
    helper(root,0)
    function helper(node,level){
        if(!node) return
        if(!res[level]){
            res[level] = [node.val]
        }else{
            res[level].push(node.val)
        }
        var left = node.left
        var right = node.right
        helper(left,level + 1)
        helper(right,level + 1)
    }
    return res
}
// 方法3 迭代方法改进
var levelOrder = function(root) {
    if(!root) return []
    var res = []
    var queue = [root]
    var level = 0
    while(queue.length){
        if(!res[level]){
            res[level] =[]
        }
        var length = queue.length
        while(length){
            var cur = queue.shift()
            res[level].push(cur.val)
            var left = cur.left
            var right = cur.right
            left && queue.push(left)
            right && queue.push(right)
            length -- 
        }
        
        level ++
    }
    return res
};







```