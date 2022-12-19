### 解题思路
非递归版本的前序遍历。首先打印出的必然是中间节点，然后左节点和右节点。

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
        List<Integer> list = new ArrayList<>();
        if (root != null){
            Stack<TreeNode> stack = new Stack<>();
            stack.add(root);
            while(!stack.isEmpty()){
                root = stack.pop();
                list.add(root.val);
                if (root.right != null){
                    stack.add(root.right);
                }
                if (root.left != null){
                    stack.add(root.left);
                }
            }
        }
        return list;
    }
}


```