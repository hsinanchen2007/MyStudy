### 解题思路
迭代，用两个栈来同时维护更新节点和路径
1 第一个栈用来存放节点值，我们称之为节点栈。第二个栈用来存放到遍历到当前节点的路径，称之为路径栈。
2 当遇到叶子结点的时候把路径栈中最后入栈的路径弹出即可，然后继续判断节点栈是否为空，直到节点栈为空结束循环

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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths=new ArrayList<String>();
        if(root==null) return paths;
        Queue<TreeNode> node_queue=new LinkedList<TreeNode>();
        Queue<String> path_queue=new LinkedList<String>();
        node_queue.add(root);
        path_queue.add(Integer.toString(root.val));
        while(!node_queue.isEmpty()){
            TreeNode node=node_queue.poll();
            String path=path_queue.poll();
            if(node.right==null&&node.left==null){
                paths.add(path);
            }
            if(node.left!=null){
                node_queue.add(node.left);
                path_queue.add(path+"->"+Integer.toString(node.left.val));
            }
            if(node.right!=null){
                node_queue.add(node.right);
                path_queue.add(path+"->"+Integer.toString(node.right.val));
            }
        }
        return paths;
    }
}
```