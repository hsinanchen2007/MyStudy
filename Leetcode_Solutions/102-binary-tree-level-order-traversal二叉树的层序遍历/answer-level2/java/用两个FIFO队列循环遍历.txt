### 解题思路
用两个FIFO队列循环遍历

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if(root == null)
            return ans;
        LinkedList<TreeNode> list1 = new LinkedList<>();    //FIFO队列
        LinkedList<TreeNode> list2 = new LinkedList<>();    //FOFO队列
        list1.add(root);
        while(list1.size() > 0){
            LinkedList<Integer> val1 = new LinkedList<>();
            while(list1.size() > 0){
                TreeNode node = list1.removeFirst();
                val1.add(node.val);
                if(node.left != null)
                    list2.add(node.left);
                if(node.right != null)
                    list2.add(node.right);
            }
            if(val1.size() > 0)
                ans.add(val1);
            
            LinkedList<Integer> val2 = new LinkedList<>();
            while(list2.size() > 0){
                TreeNode node = list2.removeFirst();
                val2.add(node.val);
                if(node.left != null)
                    list1.add(node.left);
                if(node.right != null)
                    list1.add(node.right);
            }
            if(val2.size() > 0)
                ans.add(val2);
            
        }
        return ans;
    }
}
```