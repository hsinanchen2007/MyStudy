### 解题思路
深度优先遍历二叉搜索树，如果当前节点值在L和R之间，那么就都搜索累加节点值。
否则如果当前节点值大于L那么递归深度遍历当前节点的左子树即dfs(node.left, L, R);
如果当前节点值小于R那么递归遍历当前节点的右子树即dfs(node.right, L, R)
最后返回累加值。
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
    int sum;
    public int rangeSumBST(TreeNode root, int L, int R) {
        sum = 0;
        dfs(root, L, R);
        return sum;
    }


    public void dfs(TreeNode node, int L, int R){
        if(node != null){
            if(node.val >= L && node.val <= R){
                sum += node.val;
            }
            if(node.val > L){
                dfs(node.left, L, R);
            }
            if(node.val < R){
                dfs(node.right, L, R);
            }
        }
    }
}
```