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
    public List<Integer> inorderTraversal(TreeNode root) {
ArrayList<Integer> res=new ArrayList<>();
Stack<TreeNode> stack=new Stack<>();
TreeNode curr=root;
while (curr!=null||!stack.isEmpty()) {
    while(curr!=null)
{
    stack.push(curr);
    curr=curr.left;
}
curr=stack.pop();
res.add(curr.val);
curr=curr.right;
} 
return res;
    }
   
}
```