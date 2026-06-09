### 解题思路
此处撰写解题思路
1.新建arraylist
2.利用stack
3.先pop栈顶元素
4.然后先push right children
5.最后Push left children

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
        ArrayList<Integer> output=new ArrayList<Integer>();

        if(root==null){
            return output;
        }
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.push(root);

        while(!stack.empty()){
            TreeNode n= stack.pop();
            output.add(n.val);
            if(n.right!=null){
                stack.push(n.right);
            }
            if(n.left!=null){
                stack.push(n.left);
            }
        }
        return output;

    }
}
```