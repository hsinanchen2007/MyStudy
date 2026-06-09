# 思路：
整个过程分为两步：判断是否可以进入遍历比较和遍历比较是否匹配。	

1. 判断是否可以进入遍历比较：
    - 如果A、B其中一个为null，return false；
    - 判断A、B是否满足遍历比较的条件：
        - A.val == B.val，进行遍历比较；
        - A.val != B.val，判断A.left和B或者A.right和B是否满足遍历比较的条件。

2. 遍历比较：
    - 如果A为null，但B不为null，说明A没有足够的子树来与B进行比较，匹配失败，return false；
    - 如果B为null，此时说明B已经全部匹配完毕，return true；
    - 如果A.val != B.val，此时这条遍历路线出现不匹配的节点，匹配失败，return false；
    - 剩下的情况只剩下A.val == B.val，这时继续遍历比较A.left和B.left以及A.right和B.right，两个都为true才能返回true。

# 代码：
```
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null) return false;
        
        if (A.val == B.val) {
            return isSub(A, B);
        } else {
            return isSubStructure(A.left, B) || isSubStructure(A.right, B);
        }
    }
    
    private boolean isSub(TreeNode A, TreeNode B) {
        if (A == null && B != null) return false;
        if (B == null) return true;
        if (A.val != B.val) return false;
        
        return isSub(A.left, B.left) && isSub(A.right, B.right);
    }
}
```
