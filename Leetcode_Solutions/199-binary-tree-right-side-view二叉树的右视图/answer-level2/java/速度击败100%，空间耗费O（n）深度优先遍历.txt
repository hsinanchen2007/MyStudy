### 解题思路
深度优先，代码简单

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

    ArrayList<Integer> res;
    int nowDepth;
    int maxDepth;
    public List<Integer> rightSideView(TreeNode root) {
        nowDepth = -1;
        maxDepth = -1;
        res = new ArrayList();
        DFS(root);
        return res;
    }

    private void DFS(TreeNode root){
        if(root == null) return;
        nowDepth++;
        if(nowDepth > maxDepth) {
            res.add(root.val);
            maxDepth = nowDepth;
        }
        DFS(root.right);
        DFS(root.left);
        nowDepth--;
    }
}
```