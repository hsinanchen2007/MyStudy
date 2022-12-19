### 解题思路
    其实思路很简单，就是先算出一个节点右边的最大值，那么节点的值就是右边的最大值+当前的值，此时再计算左边的值，左边的值最小也是当前节点的值，所以多写了一个参数base，base代表当前节点如果是一个节点的左节点时，节点当前的值。

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
    public TreeNode bstToGst(TreeNode root) {
        if(root==null){
            return root;
        }
        bstToGstWithBase(root,0);
        return root;
    }

    public int bstToGstWithBase(TreeNode root,int base){
        if(root==null){
            return base;
        }
        //对右边边进行执行，返回最大值，当前节点的值为右边的最大值+当前的value
        root.val += bstToGstWithBase(root.right,base);
        //对左边进行计算，算出最大值。
        int leftValue = bstToGstWithBase(root.left, root.val);
        //返回左右中较大者
        return root.val>=leftValue?root.val:leftValue;
    }

}
```