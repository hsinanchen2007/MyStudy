### 解题思路
1. 层次遍历加先序遍历，重复度高，时间长，还有更简单写法，双递归。
2. 使用map存储已访问过的路径和，查看当前路径和减去sum是否存在与map中。如果是，则加入结果中。递归之后注意回溯。

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
    private int res;
    public int pathSum(TreeNode root, int sum) {
        if(root == null) return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        res = 0;
        while(!queue.isEmpty()){
            TreeNode cur = queue.poll();
            if(cur.left != null) queue.offer(cur.left);
            if(cur.right != null) queue.offer(cur.right);
            preOrder(cur, sum);
        }
        return res;
    }

    private void preOrder(TreeNode cur, int sum){
        if(sum == cur.val)
            res += 1;
        if(cur.left != null) preOrder(cur.left, sum - cur.val);
        if(cur.right != null) preOrder(cur.right, sum - cur.val);
    }
}

class Solution {
    private Map<Integer, Integer> map;
    public int pathSum(TreeNode root, int sum) {
        map = new HashMap<>();
        map.put(0, 1);
        if(root == null) return 0;
        return helper(root, sum, 0);
    }

    private int helper(TreeNode root, int sum, int passSum){
        int res = 0;
        if(root == null) return 0;
        passSum += root.val;
        if(map.containsKey(passSum-sum)) res += map.get(passSum-sum);
        map.put(passSum, map.getOrDefault(passSum, 0) + 1);
        
        res = helper(root.left, sum, passSum) + helper(root.right, sum, passSum) + res;
        map.put(passSum, map.get(passSum) - 1);
        return res;
    }
}
```