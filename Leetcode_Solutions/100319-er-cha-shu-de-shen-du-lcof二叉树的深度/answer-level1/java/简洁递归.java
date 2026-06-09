

### 代码
执行用时 :
0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.6 MB, 在所有 Java 提交中击败了100.00%的用户
```java
class Solution {
    public int maxDepth(TreeNode root) {
        //递归结束条件
        if(root == null) return 0;
        //1是本层的高度,要加上去
        return Math.max(maxDepth(root.left),maxDepth(root.right))+1;
    }
}