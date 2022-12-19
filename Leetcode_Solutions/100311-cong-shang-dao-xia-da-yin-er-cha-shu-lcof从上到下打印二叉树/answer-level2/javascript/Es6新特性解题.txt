
# 先层序遍历再展开得到结果数组

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
var levelOrder = function (root) {
    var levels = []
    var level = 0
    walk(root, level)
    function walk(root, level) {
        if (root == null) return
        if (level == levels.length) {
            levels.push([])
        }
        levels[level].push(root.val)

        walk(root.left, level + 1)
        walk(root.right, level + 1)
    }
    var res=[]
    for(let i =0;i<levels.length;i++){
        res = [...res,...levels[i]]
        
    }
    return res
};
```