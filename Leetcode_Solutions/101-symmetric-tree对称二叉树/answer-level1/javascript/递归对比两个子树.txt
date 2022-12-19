### 解题思路
左子树的左子树对比右子树的右子树


### 代码

```javascript
var isSymmetric = function(root) {
    if(!root) {
        return true
    }
    return compareTwoTrees(root.left, root.right)
};

function compareTwoTrees(left, right) {
    if(left && right) {
        if(left.val === right.val) {
            return compareTwoTrees(left.left, right.right) && 
            compareTwoTrees(left.right, right.left)
        }
        return false
    } else if(!(left || right)) {
        return true
    }
    console.log(left, right)
    return false
    
}
```