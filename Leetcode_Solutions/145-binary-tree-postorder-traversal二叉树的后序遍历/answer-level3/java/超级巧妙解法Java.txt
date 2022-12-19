### 解题思路
此处撰写解题思路
如果会用迭代法写出二叉树的先序遍历，那么这题你一定会做。
因为先序遍历的顺序是root-left-right,后序遍历是left-right-root,所以只要用之前的方法得到root-right-left,然后将其倒置即可，是不是超简单。如果不会先序遍历的迭代方法，先写一下144题再做这题。我觉得这个方法超级巧妙，分享给大家。
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>ret=new ArrayList<>();
        if(root==null) return ret;
        Stack<TreeNode>stack=new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode t=stack.pop();
            ret.add(t.val);
            if(t.left!=null) stack.push(t.left);
            if(t.right!=null) stack.push(t.right);
        }
        Collections.reverse(ret);
        return ret;
    }
}
```