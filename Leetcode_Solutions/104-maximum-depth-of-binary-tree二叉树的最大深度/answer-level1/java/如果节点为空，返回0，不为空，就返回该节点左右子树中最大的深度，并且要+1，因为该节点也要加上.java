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
    public int maxDepth(TreeNode root) {
        //如果节点为空，返回0
        if(root == null)
            return 0;
        //否则，返回返回该节点左右子树中最大的深度+1，+1是因为要加上该节点。
        else
            return 1+max(maxDepth(root.left),maxDepth(root.right));
    }
    //定义左右子树选取最大深度的函数
    static int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
        
    }
}
```