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
        List<Integer> list = new ArrayList<Integer>();
        Stack <TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while(!stack.isEmpty() || node != null){
            if(node != null){//一直向左遍历，将父节点压入栈
                stack.push(node);
                node = node.left;
            }else{//弹出父节点，之后访问其右子树
                node = stack.pop();
                list.add(node.val);//访问该节点
                node = node.right;
            }
        }
        return list;
    }
    
}
```