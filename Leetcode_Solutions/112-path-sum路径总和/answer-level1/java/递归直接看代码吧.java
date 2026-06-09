### 解题思路
左右子树遍历就可以了。具体看代码应该很好理解。
### 代码

```java
class Solution {

    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)
            return false;
        if(root.left==null&&root.right==null)
            return sum-root.val==0;

        return hasPathSum(root.left,sum-root.val)||
                hasPathSum(root.right,sum-root.val);
    }
}
```