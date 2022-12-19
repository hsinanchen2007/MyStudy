### 解题思路
![WechatIMG2.jpeg](https://pic.leetcode-cn.com/b21b377264f1aebd9c771a14f8286ccdf91b28d6c6d214a2c5c3d9975455f6e2-WechatIMG2.jpeg)


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
    int lastValue = 0;
    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        return root;
    }

    private void dfs(TreeNode root){
        if(root == null){
            return;
        }
        if(root.right!=null){
            dfs(root.right);
        }
        lastValue+=root.val;
        root.val = lastValue;
        if(root.left!=null){
            dfs(root.left);
        }
    }
}
```