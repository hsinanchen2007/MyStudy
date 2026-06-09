### 解题思路
非递归借助队列

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
    //非递归
    public int maxDepth(TreeNode root){
    if(root == null) return 0;
    Queue<TreeNode> queue = new LinkedList<>();
    int count,deep;
    
    queue.offer(root);
    count=1;deep=0;
    while(!queue.isEmpty()){
      TreeNode node = queue.remove();
      count--;
      if(node.left != null) queue.offer(node.left);
      if(node.right != null) queue.offer(node.right);
      
      if(count == 0){
        deep++;
        count=queue.size();
      }
    }
    return deep;
  }

    //递归
    public int maxDepth2(TreeNode root) {
    if(root == null) return 0;

    int left = maxDepth(root.left);
    int right = maxDepth(root.right);

    return Math.max(left,right)+1;
  }

}
```