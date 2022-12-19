### 解题思路
之前的层次遍历可以直接用一个队列解决，这次的特殊一点，但也可以用两个栈解决
两个栈来回倒子节点

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
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null)return ans;
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);
        boolean state = true;
        while(!s1.isEmpty() || !s2.isEmpty()){
            List<Integer> row = new ArrayList<>();
            if(state){
                while(!s1.isEmpty()){
                    TreeNode node = s1.pop();
                    row.add(node.val);
                    if(node.left != null){
                    	s2.push(node.left);
                    }
                    if(node.right != null){
                        s2.push(node.right);
                    }
                }
            }else {
                while(!s2.isEmpty()){
                    TreeNode node = s2.pop();
                    row.add(node.val);
                    if(node.right != null){
                    	s1.push(node.right);
                    }
                    if(node.left != null){
                        s1.push(node.left);
                    }
                }
            }
            ans.add(row);
            state = !state;
        }
        return ans;
    }
}
```