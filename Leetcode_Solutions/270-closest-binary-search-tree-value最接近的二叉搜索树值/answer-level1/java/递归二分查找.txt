### 解题思路
因为已经是一个颗二分搜索树，要找的值要么在左边要么在右边，让然还要考虑可能是degree节点，可以采用递归二分查找。


![Screen Shot 2020-01-01 at 15.53.23.png](https://pic.leetcode-cn.com/bacc588aa041cc5760013b9f46b437596fc544c552228bf0033bce843ea24301-Screen%20Shot%202020-01-01%20at%2015.53.23.png)


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
    public int closestValue(TreeNode root, double target) {
        return closest(root, target).val;
    }

    public TreeNode closest(TreeNode root, double target) {

        double delta = Math.abs(target - root.val);

        if(target < root.val) {
            if(root.left!=null) {
                TreeNode left = closest(root.left, target);
                return Math.abs(left.val-target) > delta ? root : left;
            } else {
                return root;
            }
            
        }

        if(target > root.val){
            if(root.right!=null) {
                TreeNode right = closest(root.right, target);
                return Math.abs(right.val-target) > delta ? root : right;
            } else {
                return root;
            }
        }
        
        return root;
    }
}
```