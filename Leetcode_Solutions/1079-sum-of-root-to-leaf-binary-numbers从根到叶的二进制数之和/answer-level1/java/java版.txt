### 解题思路
二进制数转换成十进制整数就是乘2的问题,比如1010=2^(3)*1+2^(2)*0+2^(1)*1+2^(0)*0=10.
1 当我们遍历的根节点时，根节点是二进制的最高位，直到遍历到叶子结点之前，每次遍历到子节点时都让根节点
乘2，其他节点也是如此。

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
    int sum=0;
    public int sumRootToLeaf(TreeNode root) {
        if(root==null) return -1;
        helper(root,0);
        return sum;
    }
    public void helper(TreeNode root,int num){
            if(root==null) return;
            num+=root.val;
            if(root.left==null&&root.right==null){
                 sum+=num;
            }
            helper(root.left,num*2);
            helper(root.right,num*2);
    } 
}
```