![image.png](https://pic.leetcode-cn.com/ff18358fad395a75d9107b883a7507c7f9c1ef86d2807a6c158c65de395bbbfd-image.png)




```
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null)
            return false;
        return isEqual(s,t)||isSubtree(s.left,t)||isSubtree(s.right,t);
    }

    private boolean isEqual(TreeNode s,TreeNode t){
        if(s==null&&t==null)
            return true;
        if(s==null||t==null)
            return false;
        
        return s.val==t.val&&isEqual(s.left,t.left)&&isEqual(s.right,t.right);
    }
}
```
