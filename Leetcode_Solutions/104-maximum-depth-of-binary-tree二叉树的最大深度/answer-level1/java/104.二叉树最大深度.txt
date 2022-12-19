### 解题思路
如下图
1、递归左子树，当第一次遇到叶子节点d时，以d为形参，调用maxDepth(),其leftDepth与rightDepth都为0，return 0 + 0 + 1。实际上是计算了以d为根节点的子树高度。
2、步骤1中的返回值赋给了以b为形参时，调用maxDepth()函数时的变量leftDepth，即leftDepth=1。也就是b节点的左子树高度为1。
3、由此类推，得到以b为形参调用maxDepth()时的rightDepth也等于1
4、b节点的调用结束，以b为根节点的子树高度即为max(leftDepth,rightDepth) + 1 = 2。
5、继续这个过程，最终得到a为根节点的树的leftDepth=2，rightDepth=1,树高为max(2,1)+1=3

![58DFB615CE4BE94FDB4DB0721DCF4169.png](https://pic.leetcode-cn.com/ce3762b52bb906bce86ba809951555f6965388ea1b4ecd58d4287b02418fc8cb-58DFB615CE4BE94FDB4DB0721DCF4169.png)


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
        if(root == null){
            return 0;
        }else{
            //递归判断左子树深度
            int leftDepth = maxDepth(root.left);
            //递归判断右子树深度
            int rightDepth = maxDepth(root.right);
            //加根节点
            return Math.max(leftDepth,rightDepth) + 1;
        }
    }
}
```