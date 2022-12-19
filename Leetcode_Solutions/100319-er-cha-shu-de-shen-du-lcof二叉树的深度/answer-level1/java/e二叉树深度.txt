### 解题思路
利用双端队列进行层遍历，直到遍历到每层的最右边一个节点，才会深度加一。

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
        if(root==null) return 0;
        int depth=0;
        TreeNode nowNode=null;
        TreeNode queueLast=root;//每一层的最右边结点
        Deque<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            nowNode=queue.poll();
            if(nowNode.left!=null) queue.offer(nowNode.left);
            if(nowNode.right!=null) queue.offer(nowNode.right);
            if(nowNode==queueLast){
                queueLast=queue.peekLast();
                depth++;
            }
        }
        return depth;

    }
}
```