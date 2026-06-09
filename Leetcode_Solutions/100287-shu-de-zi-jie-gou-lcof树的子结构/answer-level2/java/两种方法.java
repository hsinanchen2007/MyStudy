### 解题思路

两个方法
1. 对两个node进行水平遍历，如果A包含B，则成功
2. 对A进行遍历，当a.val==b.val时，check A和B是否匹配

### 代码

```java
class Solution {
    // 对A进行遍历，如果a.val == b.val,则check是否匹配
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A == null || B == null) return false;
        return preTravel(A, B);
    }
    private boolean preTravel(TreeNode node, TreeNode target) {
        if (node == null) return false;
        if (node.val == target.val) return isMatch(node, target);
        return preTravel(node.left, target) || preTravel(node.right, target);
    }
    private boolean isMatch(TreeNode a, TreeNode b) {
        if (b == null) return true;
        if (a != null && b!= null && a.val == b.val) return isMatch(a.right, b.right) && isMatch(a.left, b.left);
        return false;
    }
}
```