### 解题思路1.利用一个setset集合，里面不包括相同的元素，在遍历树的同时，判断集合中是否包含k-cur.val
的值，其中cur是当前正在访问的结点。


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
    Set<Integer> set=new HashSet<>();
    public boolean findTarget(TreeNode root, int k) { 
        if(root==null) return false;
        if(set.contains(k-root.val)) return true;
        set.add(root.val);
        return findTarget(root.left,k)||findTarget(root.right,k);
       
    }
}
```