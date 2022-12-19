### 解题思路
用数组minMax记录遍历当前路径下的最大值和最小值。注意要将最大值和最小值的状态保存下来，回溯时恢复原来的状态。

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
    public int result;
    public int maxAncestorDiff(TreeNode root) {
        result = 0;
        int[] minMax = {Integer.MAX_VALUE, Integer.MIN_VALUE};
        helper(root, minMax);
        return result;
    }

    public void helper(TreeNode root, int[] minMax)
    {   
        if (root == null)
            return;
        //min max保存原本最大值和最小值
        int min = minMax[0];
        int max = minMax[1];

        if (root.val < min)
            minMax[0] = root.val;
        if (root.val > max)
            minMax[1] = root.val;
        
        if (minMax[1] - minMax[0] > result)
            result = minMax[1] - minMax[0];

        helper(root.left, minMax);
        helper(root.right, minMax);
        //回溯时恢复原本状态
        minMax[0] = min;
        minMax[1] = max;
        
    }
}
```
![image.png](https://pic.leetcode-cn.com/ecba6d997362213ad1c68adf31c3bf97334a771f1dfc5cc2db0373bf81aaf4e3-image.png)
