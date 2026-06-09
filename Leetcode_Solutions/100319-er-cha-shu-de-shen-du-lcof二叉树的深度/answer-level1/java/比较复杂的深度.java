### 解题思路

第一种方法是利用递归，求树的深度

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
        if(root==null){
            return 0;
        }else{
            return maxDepth(root,1);
        }
    }

    public int maxDepth(TreeNode root,int deep){
        if(root.left==null&&root.right==null){
            return deep;
        }
        int left=deep;
        int right=deep;
        if(root.left!=null){
            left=maxDepth(root.left,++left);
        }
        if(root.right!=null){
            right=maxDepth(root.right,++right);
        }
        return left>right?left:right;
        
    }
}
```

第二种方式是借助队列的方式来层次遍历

```
class Solution {
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        Deque<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        TreeNode flag=root;
        int deep=0;
        while(!queue.isEmpty()){
            TreeNode node=queue.poll();
            if(node.left!=null){
                queue.offer(node.left);
            }
            if(node.right!=null){
                queue.offer(node.right);
            }
            if(flag==node){
                flag=queue.peekLast();
                deep++;

            }
        }
        return deep;

    }
}
```