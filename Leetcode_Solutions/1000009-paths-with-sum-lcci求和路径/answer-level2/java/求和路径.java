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
    int count=0;
    public int pathSum(TreeNode root, int sum) {
       if(root==null)
           return 0;
        dfs(root,sum);
        pathSum(root.left,sum);
        pathSum(root.right,sum);
        return count;
    }

    public void dfs(TreeNode root,int sum)
    {
        if(root==null)
            return ;
        sum-=root.val;
        if(sum==0)
            count++;      //仅仅是count++,并不是结束
        dfs(root.left,sum);
        dfs(root.right,sum);
    }
}
```