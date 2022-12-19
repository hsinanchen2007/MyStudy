### 思路：
- 其实和求二叉树的最大深度思路有些类似，不过当二叉树退化为链表时需要特判一下，因为此时是计入最小长度的，依旧取二者最小值会导致无法继续统计。

### 代码：
```java
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.right == null ^ root.left == null) 
            return 1 + Math.max(minDepth(root.left), minDepth(root.right));
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }
}
```