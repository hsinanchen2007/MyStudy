### 解题思路
递归DFS与官方题解一致。
非递归时，可以选用队列实现广度优先搜索，也可以选用栈实现深度优先搜索。两者代码实现几乎一致，只是选用的数据结构不同。
非递归与官方不同的是，最大深度仅在遍历到叶子结点下的空结点时更新，更新值为空结点深度-1。因此也不用初始判空操作。


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

    // 递归DFS
     public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }else {
            int lDeep = maxDepth(root.left)+1;
            int rDeep = maxDepth(root.right)+1;
            return Math.max(lDeep, rDeep);
        }

    }


// 队列BFS
    public static int maxDepth(TreeNode root) {
        Queue<Pair<TreeNode,Integer>> queue = new LinkedList();
        queue.add(new Pair(root,1));
        int max=0;
        while (!queue.isEmpty()){
            Pair current=(Pair)queue.poll();
            TreeNode current_node= (TreeNode) current.getKey();
            int current_level= (int) current.getValue();
            if(current_node!=null) {
                queue.add(new Pair(current_node.left,current_level+1));
                queue.add(new Pair(current_node.right,current_level+1));
            }else {
                max = Math.max(current_level-1, max);
            }
        }
        return max;       
    }


// 栈DFS
    public static int maxDepth(TreeNode root) {
        Stack<Pair<TreeNode,Integer>> stack = new Stack<>();
        stack.add(new Pair(root,1));
        int max=0;
        while (!stack.isEmpty()){
            Pair current=(Pair)stack.pop();
            TreeNode current_node= (TreeNode) current.getKey();
            int current_level= (int) current.getValue();
            if(current_node!=null) {
                stack.push(new Pair(current_node.right,current_level+1));
                stack.push(new Pair(current_node.left,current_level+1));
            }else {
                max = Math.max(current_level-1, max);
            }
        }
        return max;
    }


}
```