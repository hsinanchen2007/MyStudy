### 解题思路 前序排列是利用一个额外的栈结构来存储所有的右结点，


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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list=new LinkedList<>();
        if(root==null) return list;
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        TreeNode temp=null;
        while(!stack.isEmpty()){
            temp=stack.pop();
            if(temp.right!=null) stack.push(temp.right);
            if(temp.left!=null) stack.push(temp.left);
            list.add(temp.val);
        }
        return list;
    }
}
```