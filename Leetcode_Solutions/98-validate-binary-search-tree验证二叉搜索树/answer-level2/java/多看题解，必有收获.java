### 解题思路

之前的代码，没注意右子树所有数必须**都**大于节点，递归做的
递归基本模块：
***1.出口
2.需要上一步返回的什么
3.这一步做什么***
一般来说，可以先写第三步，再写第二步
之后的代码就是官方解答差不多，挺酷的，val设为左子树上界的同时，也判断了基本逻辑，学就完事了，冲！
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
    public boolean help(TreeNode node, Integer lower, Integer upper) {
        if (node==null) return true;
        int val = node.val;
        if (!help(node.left,lower,val)) return false;
        if(!help(node.right,val,upper)) return false;
        if (upper!=null&&val>=upper) return false;
        if (lower!=null&&val<=lower) return false;
        return true;
    }

    public boolean isValidBST(TreeNode root) {
       return help(root,null,null);
    }
}

```
```
class Solution {
    public boolean help(TreeNode node, Integer lower, Integer upper) {
        if (node==null) return true;
        int val = node.val;
        if (!help(node.left,lower,val)) return false;
        if(!help(node.right,val,upper)) return false;
        if (upper!=null&&val>=upper) return false;
        if (lower!=null&&val<=lower) return false;
        return true;
    }

    public boolean isValidBST(TreeNode root) {
        return help(root,null,null);
    }
}
```
