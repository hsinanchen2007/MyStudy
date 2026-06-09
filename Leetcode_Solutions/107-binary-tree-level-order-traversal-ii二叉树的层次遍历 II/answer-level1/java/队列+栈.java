### 解题思路
在使用队列层次遍历的基础上，使用栈进行逆序输出

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Stack<List<Integer>> stack = new Stack<>();
        Queue<TreeNode> queue = new ArrayDeque<>();
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        queue.add(root);
        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            for(int i = 0; i < size; i++){
                root = queue.poll();
                list.add(root.val);
                if (root.left != null){
                    queue.add(root.left);
                }
                if (root.right != null){
                    queue.add(root.right);
                }
            }
            stack.push(list);
        }
        while(!stack.isEmpty()){
            res.add(stack.pop());
        }
        return res;
    }
}
```