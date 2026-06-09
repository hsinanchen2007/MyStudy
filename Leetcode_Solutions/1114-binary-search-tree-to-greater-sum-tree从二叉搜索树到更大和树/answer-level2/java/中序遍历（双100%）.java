```
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        int a = backtrace(root,0);
        return root;
    }
    public int backtrace(TreeNode root,int count){
        if(root == null)
            return count;
        if(root.right==null){
            root.val = root.val+count;
            return backtrace(root.left,root.val);
        }   
        root.val = root.val+ backtrace(root.right,count);
        return backtrace(root.left,root.val);
    }
}
```

![捕获.JPG](https://pic.leetcode-cn.com/c907c0b0905326b70c04da213280a711a474328598751d084bfb67062baebcb8-%E6%8D%95%E8%8E%B7.JPG)
