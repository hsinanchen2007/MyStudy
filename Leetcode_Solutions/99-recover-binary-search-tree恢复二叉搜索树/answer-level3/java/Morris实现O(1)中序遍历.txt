对于这个问题，有一个需要考虑的地方就是如果交换的两个节点不相邻，例如下面这样，那最后交换的节点应该是6和2两个点，也就是需要交换的两个值为第一次突变的第一个值和第二次突变的第二个值
> 1 6 3 4 2 8

如果两个交换的节点相邻，例如
> 1 3 2 4

此时需要交换的两个值就是3和2，注意这里突变指的是当前的值比后一个值要大，清楚了这个以后，我们就可以使用中序遍历，找到这两个节点，最后交换它们的值就ok了。

<br>
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
    
    public void recoverTree(TreeNode root) {
        TreeNode t1=null,t2=null,prev=null;
        
        TreeNode cur=root;
        
        while(cur!=null){
            
            if(cur.left==null){
                if(prev!=null&&prev.val>cur.val){
                    if(t1==null) t1=prev;
                    t2=cur;
                }
                
                prev=cur;
                cur=cur.right;
            }else{
                TreeNode p=cur.left;
                while(p.right!=null&&p.right!=cur) p=p.right;
                
                if(p.right==null){
                    p.right=cur;
                    cur=cur.left;
                }else{
                    if(prev!=null&&prev.val>cur.val){
                        if(t1==null) t1=prev;
                        t2=cur;
                    }
                    
                    prev=cur;//将根节点赋值给prev
                    p.right=null;
                    cur=cur.right;
                }
            }
        }
        
        int tmp=t1.val;
        t1.val=t2.val;
        t2.val=tmp;
    }
}
```