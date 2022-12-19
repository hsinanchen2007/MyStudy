从根节点开始递归向下更新每个节点的值，如果是叶子节点，则加到最终结果里。

![129-1.png](https://pic.leetcode-cn.com/13e460c570c138e5bf25040d02bac1f18bf4582bf0c5458ffea9fdfa3a1d85ed-129-1.png)


绿色: 代表当前遍历到的节点
红色: 代表已经遍历过的节点
黄色: 叶子节点

```
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
    private int sum;
    public int sumNumbers(TreeNode root) {
        sum = 0;
        updateNum(root, 0);
        return sum;
    }

    private void updateNum(TreeNode root, int parent){
        if(root==null){
            return;
        }
        
        int current = parent * 10 + root.val;
        if(root.left==null && root.right==null){
            sum += current;
            return;
        }

        updateNum(root.left, current);
        updateNum(root.right, current);
    }
}
```
