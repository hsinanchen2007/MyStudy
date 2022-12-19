### 解题思路

手写思路：

![IMG_0454.PNG](https://pic.leetcode-cn.com/c9f1c80b383cf14360407785fc8dbb7b74486f88353501c8fc930b7c339c74bb-IMG_0454.PNG)


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
    public String tree2str(TreeNode t) {
        if(t==null) return "";
        if(t.left==null && t.right==null) return t.val+"";
        if(t.right==null) return t.val+"("+tree2str(t.left)+")";
        return t.val+"("+tree2str(t.left)+")"+"("+tree2str(t.right)+")";
    }
}
```