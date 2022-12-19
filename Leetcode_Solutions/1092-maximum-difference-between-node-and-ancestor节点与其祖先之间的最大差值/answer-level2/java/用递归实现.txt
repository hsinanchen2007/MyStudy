用递归来解决此问题，递归函数两个数值参数分别记录当前节点的所有祖宗节点的上界和下界
```
public class Solution {
    public int maxAncestorDiff(TreeNode root) {
        if(root==null){
            return 0;
        }else{
            return maxDiff(root,root.val,root.val);
        }
    }
    public int maxDiff(TreeNode root, int a, int b){
        int cur = root.val;
        if(cur<a){
            a = cur;
        }else if(cur>b){
            b = cur;
        }
        if(root.left!=null&&root.right!=null){
            return Math.max(maxDiff(root.left,a,b),maxDiff(root.right,a,b));
        }
        if(root.left!=null){
            return maxDiff(root.left,a,b);
        }
        if(root.right!=null){
            return maxDiff(root.right,a,b);
        }
        return b-a;
    }
}
```