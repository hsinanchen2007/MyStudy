### 解题思路
在中序遍历二叉树的基础上，记录最终树的层数和每一层的总和，从中拿到最大总和的那一层

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
    Map<Integer,Integer> levelSum = new HashMap<>();
    int maxDepthLevel = 0;
    public int maxLevelSum(TreeNode root) {
        findLevelSum(1,root);
        int maxSum = Integer.MIN_VALUE;
        int res = 0;
        for(int i=1;i<=maxDepthLevel;i++){
            if(levelSum.get(i)>maxSum){
                maxSum = levelSum.get(i);
                res = i;
            }
        }
        return res;
    }
    private void findLevelSum(int level,TreeNode node){
        if(node == null){
            return;
        }
        maxDepthLevel = Math.max(maxDepthLevel,level);
        findLevelSum(level+1,node.left);
        levelSum.put(level,levelSum.getOrDefault(level,0)+node.val);
        findLevelSum(level+1,node.right);
    }
}
```