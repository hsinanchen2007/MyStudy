### 解题思路
此处撰写解题思路

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
    public int number=0;
    public int result;
    public int kthSmallest(TreeNode root, int k) {
        dfs(root,k);
        return result;
    }
    public void dfs(TreeNode root,int k){
        if(root==null){
            return;
        }
        dfs(root.left,k);
        this.number=this.number+1;
        if(number==k){
            this.result=root.val;
            return;
        }
        dfs(root.right,k);
    }
}
```