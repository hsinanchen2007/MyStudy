### 解题思路 其核心本质是利用中序遍历第k-1个元素即可，


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
    HashMap<Integer,Integer> map=new HashMap<>();
    int i=0;
    public int kthSmallest(TreeNode root, int k) {
       inOrder(root);
       return map.get(k-1);
    }
    public void inOrder(TreeNode root){
        if(root==null) return;
      
        inOrder(root.left);
        map.put(i++,root.val);
        inOrder(root.right);
       
        
        
    }
}
```