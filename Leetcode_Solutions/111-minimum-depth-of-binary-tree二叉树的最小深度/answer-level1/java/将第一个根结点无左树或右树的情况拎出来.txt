![image.png](https://pic.leetcode-cn.com/6642f282f0b74ab3e1f790abee991d8d86bce896bef4d0b2e96bd28013827387-image.png)

```
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        if(null != root.left && null != root.right){
            int leftHeight = minDepth(root.left);
            int rightHeight = minDepth(root.right);
            return Math.min(leftHeight,rightHeight) + 1;
        }
        int leftHeight2 = minDepth(root.left);
        int rightHeight2 = minDepth(root.right);
        return Math.max(leftHeight2,rightHeight2) + 1;
    }
}
```
