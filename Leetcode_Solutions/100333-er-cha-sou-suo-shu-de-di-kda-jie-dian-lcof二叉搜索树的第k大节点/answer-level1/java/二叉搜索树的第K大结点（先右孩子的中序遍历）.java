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
    List<Integer> list = new ArrayList<>();
    
    public int kthLargest(TreeNode root, int k) {
        helper(root);
        return list.get(k - 1);
    }

    public void helper(TreeNode node){
        if(node == null)return;
        helper(node.right);
        list.add(node.val);
        helper(node.left);

    }
}
```