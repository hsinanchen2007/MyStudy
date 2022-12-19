### 解题思路
分为DFS和BFS两种方式求解
DFS:
    我们可以通过自下而上的方式进行
    进行了一个后序遍历,获取到left的叶子节点其实就是对叶子节点的left和right进行赋值并计算该节点的值
    整个递归都是自下而上的相同操作
BFS：
    我们通过自上而下的方式
    size：
        每一层对应的节点数,当size = 0的时候也就是需要进行下一层的计算了

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
    public int maxDepth(TreeNode root) {
        // return testBfs(root);
        return testDfs(root);
    }
    public int testDfs(TreeNode node){
         if(node == null){
             return 0;
         }   
        // int left = testDfs(node.left);
        // int right = testDfs(node.right);
        // return Math.max(left,right)+1;
        return Math.max(testDfs(node.left),testDfs(node.right)) + 1;
    }
    public int testBfs(TreeNode root){
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList();
        int h = 0;
        int size = 1;
        if(node == null){
          return 0;  
        } 
        queue.offer(node);
        while(!queue.isEmpty()){
            node = queue.poll();
            size--;
            if(node.left!=null){
            queue.offer(node.left);
            }
            if(node.right!=null){
            queue.offer(node.right);
            }
            if(size == 0){
                size = queue.size(); 
                h++;
            } 
        }
        return h;
    }
}
```