### 解题思路
此处撰写解题思路

### 代码

```java
![572.另一个树的子树.png](https://pic.leetcode-cn.com/2f027e3fe26c38b49f0f729d07e72371d83275104928fbd4933d45888aa196b5-572.%E5%8F%A6%E4%B8%80%E4%B8%AA%E6%A0%91%E7%9A%84%E5%AD%90%E6%A0%91.png)
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

    boolean flag = false;

    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null) return false;
        flag = true;
        helper(s, t);

        if(!flag) isSubtree(s.left, t);
        if(!flag) isSubtree(s.right, t);

        return flag;

    }

    private void helper(TreeNode sSub, TreeNode t){

        if(sSub == null && t == null) return;
        else if(sSub != null && t != null){
            if(sSub.val == t.val){
                helper(sSub.left, t.left);
                helper(sSub.right, t.right);
            }
            else flag = false;
        }
        else{
            flag = false;
            return;
        }

        

    }
}
```