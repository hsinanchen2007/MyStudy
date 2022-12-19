
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
//中序遍历法
//同倒数第k个节点的解法一样
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        helper(root,list);
        return list.get(k-1); 
    }
    public void helper(TreeNode root,ArrayList<Integer> list){
        if (root == null) return;
        helper(root.left,list);
        list.add(root.val);
        helper(root.right,list);
    }
}
```