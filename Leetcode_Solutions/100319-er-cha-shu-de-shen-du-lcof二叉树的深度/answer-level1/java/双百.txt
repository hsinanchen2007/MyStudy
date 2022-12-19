### 解题思路
![image.png](https://pic.leetcode-cn.com/b052f200a19dba970ef729289a2e3c39c4a637a0efe13a3185c3b5fdca0c5e81-image.png)
递归，分别对根节点的左右子树进行递归操作，最后得到的最大深度为左右子树中最大深度值加1.
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
   int res= 0;
    public int maxDepth(TreeNode root) {
        
        return depth(root,res);
    }

    private int depth(TreeNode root, int res) {
        if(root == null){
            return res;
        }
        int left = depth(root.left,res);
        int right = depth(root.right,res);
        res++;
        return Math.max(left,right)+1;
    }
}
```