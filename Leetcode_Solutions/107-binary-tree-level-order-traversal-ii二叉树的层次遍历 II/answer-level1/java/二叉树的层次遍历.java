### 解题思路
也就是在102基础上加上了栈的操作。
先把每一层的列表加入到栈中。最后弹栈添加到总列表中。

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
    //就是在层次遍历的基础上加上栈操作
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null)
            return new ArrayList<>();

        Stack<List<Integer>> stack = new Stack<>();
        List<List<Integer>> lists = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root);

        while(!queue.isEmpty()){
            List<Integer> vals = new ArrayList<>();
            List<TreeNode> nodes = new ArrayList<>();
            while(!queue.isEmpty()){
                TreeNode node = queue.poll();
                if(node.left != null)
                    nodes.add(node.left);
                if(node.right != null)
                    nodes.add(node.right);
                vals.add(node.val);
            }
            stack.push(vals);
            while(nodes.size() != 0){
                queue.offer(nodes.get(0));
                nodes.remove(0);
            }
        }

        while(!stack.isEmpty()){
            List<Integer> list = stack.pop();
            lists.add(new ArrayList<>(list));
        }
        return lists;
    }
}
```