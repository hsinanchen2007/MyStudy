执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
85.17%
的用户
内存消耗 :
34 MB
, 在所有 Java 提交中击败了
86.98%
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p!=null&&q!=null&&p.val==q.val){
            return isSameTree(p.right,q.right)&&isSameTree(p.left,q.left);
        }else if(p==null&&q==null){
            return true;
        }else{
            return false;
        }
    }
}
```
