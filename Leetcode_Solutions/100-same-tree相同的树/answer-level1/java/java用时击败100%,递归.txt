### 解题思路
此处撰写解题思路
使用递归

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
    boolean isSame=true;
    public boolean isSameTree(TreeNode p, TreeNode q) {
        inOrder(p,q);
        return isSame;
    }
    public void inOrder(TreeNode p, TreeNode q){
        if(p==q&&p==null)
            return ;
        if(p==null&&q!=null){
            isSame=false;
            return;
        }
        if(q==null&&p!=null){
            isSame=false;
            return;
        }
        if(q.val!=p.val){
            isSame=false;
            return ;
        }
        if(isSame)
            inOrder(p.left,q.left);
        if(isSame)
            inOrder(p.right,q.right);
    }
}
```