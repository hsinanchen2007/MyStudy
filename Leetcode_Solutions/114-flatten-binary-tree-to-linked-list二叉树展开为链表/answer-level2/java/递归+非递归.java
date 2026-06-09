### 解题思路
递归+非递归

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
    private TreeNode lastNode;
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        
        if(lastNode != null){
            lastNode.right = root;
            lastNode.left = null;
        }

        TreeNode right = root.right;
        lastNode = root;
        flatten(root.left);
        flatten(right);
    }
}
```

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
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);
        while(!stack.isEmpty()){
            root = stack.pop();
            if(root.right != null){
                stack.add(root.right);
            }
            if(root.left != null){
                stack.add(root.left);
            }

            root.left = null;
            if(!stack.isEmpty()){
                root.right = stack.peek();
            }
        }
    }
}
```
