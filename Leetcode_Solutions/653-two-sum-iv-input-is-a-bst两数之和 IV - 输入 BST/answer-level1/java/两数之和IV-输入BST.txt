### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        //遍历二叉搜索树
        HashSet<Integer> hashset=new HashSet<Integer>();
        return preOrder(root,hashset,k);
    }

    public boolean preOrder(TreeNode root,HashSet<Integer> hashset,int k)
    {
        if(root==null)
            return false;
        if(hashset.contains(k-root.val))
            return true;
        hashset.add(root.val);
        return preOrder(root.left,hashset,k)||preOrder(root.right,hashset,k);
    }
}
```