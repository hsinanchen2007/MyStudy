### 解题思路  用一个队列记录树中的每层结点。


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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        TreeNode temp=null,leftNode=null;
        int size;
        while(!queue.isEmpty()){
            size=queue.size();
            leftNode=queue.peek();
            for(int i=0;i<size;i++){
                temp=queue.poll();
                if(temp.left!=null) queue.add(temp.left);
                if(temp.right!=null) queue.add(temp.right);
            }
        }
        return leftNode.val;
    }
}
```