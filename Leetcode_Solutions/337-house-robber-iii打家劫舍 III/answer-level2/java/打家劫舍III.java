### 解题思路
1. 通过分析题意，可基于后序遍历解决问题。首先创建辅助函数用于递归版后序遍历。判出条件是遇到null。
2. 返回值为以当前顶点为根的树，打劫当前顶点或者不打劫当前顶点的最大收益组成的Pair。
3. 根据左右子树的返回Pair对，遍历所有的可能性。
4. 首先如果打劫当前顶点，则肯定不能打劫左右子孩子。如果不打劫当前顶点，则有四种可能性：打劫或者不打劫左右子孩子。
5. 最后将结果组合Pair返回。在主函数中再返回Pair的最大值。

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
    public int rob(TreeNode root) {
        if(root == null) return 0;
        Pair<Integer, Integer> res = dp(root);
        return res.getKey() > res.getValue() ? res.getKey() : res.getValue();
    }

    private Pair<Integer, Integer> dp(TreeNode root){
        if(root == null) return new Pair(0, 0);
        Pair<Integer, Integer> leftPair = dp(root.left);
        Pair<Integer, Integer> rightPair = dp(root.right);
        int key = leftPair.getValue()+rightPair.getValue()+root.val;
        int value = Math.max(Math.max(Math.max(leftPair.getKey()+rightPair.getKey(), leftPair.getValue()+rightPair.getValue()), leftPair.getKey()+rightPair.getValue()), leftPair.getValue()+rightPair.getKey());
        return new Pair(key, value);
    }
}
```