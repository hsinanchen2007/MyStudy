### 解题思路  中序是利用遍历链表，先把左节点全入栈，然后弹出，在判断右结点。

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
        List<Integer> list=new LinkedList<>();
        Stack<TreeNode> stack=new Stack<>();
        if(root==null) return list;
        TreeNode cur=root;
        while(!stack.isEmpty()||cur!=null){ 
            while(cur!=null){  
                stack.push(cur);
                cur=cur.left;
            }
            TreeNode node=stack.pop();
            list.add(node.val);
            cur=node.right;
        }
        return list;
    }
}
```