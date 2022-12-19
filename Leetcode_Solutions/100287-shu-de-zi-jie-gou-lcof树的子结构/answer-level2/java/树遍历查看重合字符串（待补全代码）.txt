遍历两个树查看有无重合字符串

```
public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A==null || B==null) return false;
        String a,b;
        int r1,r2,r3;
        // 前序遍历
        a = pre(A);
        b = pre(B);
        r1 = a.indexOf(b);
        // 中序遍历
        a=mid(A);
        b=mid(B);
        r2 = a.indexOf(b);
        // 后序遍历
        a=pos(A);
        b=pos(B);
        r2 = a.indexOf(b);
        return r1+r2+r2>-3;        
    }
```
