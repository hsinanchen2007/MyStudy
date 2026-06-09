### 解题思路
![微信图片_20200220174501.png](https://pic.leetcode-cn.com/3787dc8f4beb15fac294c8eca9cf0376359d47bb2205501bc59845e665971b87-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200220174501.png)
使用比较法
首先需要一个辅助函数helper用于判断两树是否完全相同。然后对s树进行遍历，当遇到与t树根节点相等的节点时，调用helper判断当前子树与t树是否完全相同，相同则返回true，不同则继续递归遍历剩下所有节点。

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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(t==null)
            return true;
        if(s==null)
            return false;
        if(s.val==t.val&&helper(s,t)) 
            return true;
        else 
            return isSubtree(s.left,t)||isSubtree(s.right,t);
    }
    public boolean helper(TreeNode s, TreeNode t){
        if(s==null&&t==null) 
            return true;
        if(s!=null&&t!=null&&s.val==t.val){
            return helper(s.left,t.left)&&helper(s.right,t.right);
        }
        return false;
    }
}
```