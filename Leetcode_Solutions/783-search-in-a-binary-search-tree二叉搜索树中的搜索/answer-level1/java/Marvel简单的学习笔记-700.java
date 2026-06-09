### 递归

```java
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null)    return null;
        if(val < root.val)  return searchBST(root.left, val);
        if(val > root.val)  return searchBST(root.right, val);
        return root;
    }
}
```

### 迭代

```java
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        while(root != null)
        {
            if(val < root.val)      root = root.left;
            else if(val > root.val) root = root.right;
            else                    return root;
        }
        return null;
    }
}
```