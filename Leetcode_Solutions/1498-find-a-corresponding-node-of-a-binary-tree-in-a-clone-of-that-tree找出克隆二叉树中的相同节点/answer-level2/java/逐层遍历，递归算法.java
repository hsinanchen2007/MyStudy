### 解题思路
先判断父节点是否符合要求，符合直接返回，如果不符合要求递归遍历下一层

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
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        int val = target.val;
        if (cloned.val==val){
            return cloned;
        }
        return findFromChild(Arrays.asList(cloned),val);
    }

    public TreeNode findFromChild(List<TreeNode> list, int val) {
        List<TreeNode> newList = new ArrayList<>();
        for (TreeNode parent : list) {
            TreeNode left = parent.left;
            TreeNode right = parent.right;
            if (left!=null){
                if (left.val == val){
                    return left;
                }else {
                    newList.add(left);
                }
            }
            if (right!=null){
                if (right.val == val){
                    return right;
                }else {
                    newList.add(right);
                }
            }
        }
        return findFromChild(newList,val);
    }
}
```