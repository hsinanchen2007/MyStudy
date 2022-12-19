### 解题思路
1. 使用栈进行DFS遍历，用到Pair，.getKey()，.getValue()。
2. 也可以使用队列进行BFS，同样的原理
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
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
        stack.push(new Pair(root, 1));
        int depth = 0;
        while(!stack.isEmpty()){
            Pair<TreeNode, Integer> pair = stack.pop();
            TreeNode tn = pair.getKey();
            int tv = pair.getValue();
            if(tn != null){
                if(tv > depth) depth = tv;
                stack.push(new Pair(tn.left, tv + 1));
                stack.push(new Pair(tn.right, tv + 1));
            }
        }
        return depth;
    }
}
```