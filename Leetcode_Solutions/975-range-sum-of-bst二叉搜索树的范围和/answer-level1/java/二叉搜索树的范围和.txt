### 解题思路
此处撰写解题思路

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
    public int rangeSumBST(TreeNode root, int L, int R) {
        //这个题目的意思就是，如果节点的值在[L,R]这个区间内，就把自身值加到结果里，
        if(root==null)
            return 0;
        if(root.val>=L&&root.val<=R)
            return root.val+rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);
        else if(root.val<L)
            return rangeSumBST(root.right,L,R);
        else
            return rangeSumBST(root.left,L,R);
    }
}
```