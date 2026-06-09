### 解题思路
先序遍历，一旦是leafnode,就记录在Arraylist里。最后比较两个Arraylist是否一样即可。

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        add(root1,a);
        add(root2,b);
        return a.equals(b);
    }
    
    
    public void add(TreeNode node, ArrayList<Integer> list){
        if(node == null) return;
        add(node.left,list);
        if(node.left == null && node.right == null) list.add(node.val);
        add(node.right,list);
    }
}
```