执行结果：
通过
显示详情
执行用时 :
10 ms
, 在所有 Java 提交中击败了
89.07%
的用户
内存消耗 :
42.8 MB
, 在所有 Java 提交中击败了
77.84%
的用户
```
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
    
    TreeNode t1 = null;
    TreeNode t2 = null;
    public void recoverTree(TreeNode root) {
        pro(root);
        int temp = t1.val;
        t1.val =t2.val;
        t2.val=temp;
        return;
         
    }
    public void pro(TreeNode node){
        if(node==null)return;
        pro(node.left);
        if(t1==null){
            t1=node;
        }else if(t1.val>node.val){
            t2=node;
        }else{
            if(t2==null){
                t1=node;
            }else{
                return;
            }
        }
        pro(node.right);
    }
}
```
