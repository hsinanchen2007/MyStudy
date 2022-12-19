第一个树说实话没有什么用....因为每个结点的值不同,所以可以直接拿着结点的值去另外一个找

```
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (cloned==null)
            return null;
        if (target.val==cloned.val)
            return cloned;
        TreeNode middle=getTargetCopy(original, cloned.left,target);
        return middle==null?getTargetCopy(original, cloned.right, target):middle;
    }
```
