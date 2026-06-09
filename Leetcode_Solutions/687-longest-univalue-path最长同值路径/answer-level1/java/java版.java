### 解题思路
主要是搞清楚左右节点和根节点是否相等即可。然后递归求解即可。

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
    int res;
    public int longestUnivaluePath(TreeNode root) {
      res=0;
      maxLenght(root);
      return res;
}
public int maxLenght(TreeNode root){
    if(root==null) return 0;
    int left=maxLenght(root.left);//左子树上最长同值路径
    int right=maxLenght(root.right);//右子树上最长同值路径
    //从叶子结点开始和父节点比较
    int leftLength=0;
    int rightLength=0;
    //如果左节点和根节点相等，那么最长路径加1。
    if(root.left!=null&&root.left.val==root.val){
        leftLength=left+1;
    }
    //如果右节点和根节点值相等，那么最长路径加1.
    if(root.right!=null&&root.right.val==root.val){
        rightLength=right+1;
    }
    res=Math.max(res,leftLength+rightLength);//更新最大值，左右最长路径相加主要是考虑了根节点和左右节点相等的情况。
    return Math.max(leftLength,rightLength);//每次递归结束后，返回左右子树中最长的同值路径。
}
}
```