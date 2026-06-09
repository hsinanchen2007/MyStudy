0ms 100%; 34.4MB 82%

```java []
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        if(p !=null && q != null){
            if(p.val == q.val) 
                return  isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
        return false;
    }
}
```

