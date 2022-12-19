### 代码

```javascript
var isSubStructure = function(A, B) {
    if(A == null || B == null) return false
    return doesAhasB(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B)
};

const doesAhasB = (tree1, tree2) => {
    if(tree2 == null) return true
    if(tree1 == null) return false
    if(tree1.val !== tree2.val) return false
    return doesAhasB(tree1.left, tree2.left) && doesAhasB(tree1.right, tree2.right)
}


```