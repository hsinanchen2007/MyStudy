### 解题思路
很简单思路，dfs判断所有节点是否相同，注意是两棵树相同位置的两个节点同时进行比较，一旦不满足条件返回结果
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return dfs(p,q);
    }
    public boolean dfs(TreeNode p,TreeNode q){
        boolean result=true;
        if(p==null&&q==null){
            return true;
        }
        if(p!=null&&q==null){
            result=false;
        } else if(p==null&&q!=null){
            result=false;
        }
        if(!result){
            return false;
        }
        if(p.val!=q.val){
            return false;
        }
        
        boolean leftResult=dfs(q.left,p.left);
        if(!leftResult){
            return false;
        }
        boolean rightResult=dfs(q.right,p.right);
        return rightResult;
    }
}
```