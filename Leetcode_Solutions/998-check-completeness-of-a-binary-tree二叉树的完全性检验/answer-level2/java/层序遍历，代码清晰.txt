### 解题思路
此处撰写解题思路
完全二叉树，当某个节点只有左孩子或者没有孩子的时候（这个节点不饱和），这个节点之前的每个节点都有左右孩子，这个节点之后都不能有孩子，这个节点之后若是有那个节点有孩子，则不是完全二叉树，或者某个节点只有右孩子，也不是完全二叉树
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
    public boolean isCompleteTree(TreeNode root) {
        if(root==null) return true;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        boolean isleafOrleft=false;
        while(!q.isEmpty()){
            TreeNode cur=q.poll();
            if(isleafOrleft){
                //从第一个不饱和结点之后，所有的结点都不能有孩子
                if(cur.left!=null||cur.right!=null){
                    return false;
                }
            }else{
                 if(cur.left!=null&&cur.right!=null){
                    q.offer(cur.left);
                    q.offer(cur.right);
                }else if(cur.left!=null){
                    //只有左孩子
                    q.offer(cur.left);
                    isleafOrleft=true;
                }else if(cur.right!=null){
                    //只有右孩子
                    return false;
                }else{
                    //叶子结点
                    isleafOrleft=true;
                }
            }
        }
       return true;
    }
}
```