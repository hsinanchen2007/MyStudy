### 解题思路
声明一个变量curPathVal记录当前路径节点和，递归遍历每一个节点，遇到叶子节点将curPathVal与目标值sum作比较，如果相同设置flag为true,程序最后返回flag。

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
    int curPathVal=0;
    boolean flag=false;
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null) return false;
        hasPathSum2(root,sum);
        return flag;
    }
    public void hasPathSum2(TreeNode root, int sum) {
        if(flag) return ;
        curPathVal+=root.val;
        if(root.left==null&&root.right==null){
            if(curPathVal==sum) flag=true;
        }
        if(root.left!=null) hasPathSum2(root.left,sum);
        if(root.right!=null) hasPathSum2(root.right,sum);
        curPathVal-=root.val;
    }
}
```