注意处理节点为空情况：
```javascript []
 public int RangeSumBST(TreeNode root, int L, int R) {
        var val=0;
        if(root!=null&&root.val>=L&&root.val<=R)
        {
            val=root.val; 
        }else if(root==null){
            return 0;
        }
        return val+ RangeSumBST(root.left,L,R)+RangeSumBST(root.right,L,R);
    }
```

