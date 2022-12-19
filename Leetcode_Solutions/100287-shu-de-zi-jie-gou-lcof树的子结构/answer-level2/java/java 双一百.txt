就三种情况嘛：
1. A的根节点开始，B和A是否重合
2. B是否在A的左子树中
3. B是否在A的右子树中

method方法是能够判断以a，b为根的两个树，b是否完全在a中
**结果 = B是否和A以根节点开始完全重合 || B在A的左子树中 || B在A的右子树中**

```java
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(B == null) return false;
        if(A == null) return false;
        boolean res = false;
        return method(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }
    // 这个方法传入两个结点，比较以此两结点为根是否一致
    public boolean method(TreeNode a, TreeNode b){
        if(b == null) return true;
        if(a == null) return false;
        if(a.val != b.val) return false;
        return (method(a.left, b.left) && method(a.right, b.right));
    }
}
```
