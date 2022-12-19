### 解题思路
此处撰写解题思路
![截屏2020-02-06下午2.33.44.png](https://pic.leetcode-cn.com/eae13675da3f2cc28ed86553bc309801a8716cacdd41479adb957e0d4c66f543-%E6%88%AA%E5%B1%8F2020-02-06%E4%B8%8B%E5%8D%882.33.44.png)

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        return valid(root,null,null);
    }

    public boolean valid(TreeNode root,TreeNode max,TreeNode min){
        if(root == null) return true;
        if(max != null && root.val <= max.val) return false;
        if(min != null && root.val >= min.val) return false;
        return valid(root.left,max,root)&&valid(root.right,root,min);
    }
}
```