### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/56e85c925325156dbacf057006832de4b0f89a89dc5ba3aecf874926663a6d3a-%E6%8D%95%E8%8E%B7.PNG)
补充一个暴搜解法。这种方法适用于任意二叉树。速度也比较快。

思路简单：先找到节点中的最小值。第二次遍历时找到不等于该值的最小值。

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
        int min=Integer.MAX_VALUE,SecMin=Integer.MAX_VALUE;
        boolean SecMinFound=false;
        void findMinValue(TreeNode root){
            if(root==null)
                return ;
            if(root.val<min)
                min=root.val;
            if(root.left!=null)
                findMinValue(root.left);
            if(root.right!=null)
                findMinValue(root.right);
        }
        void findSecMinValue(TreeNode root){
            if(root==null)
                return ;
            if(root.val!=min&&root.val<=SecMin)
                {
                    SecMin=root.val;
                    SecMinFound=true;
                }
            if(root.left!=null)
                findSecMinValue(root.left);
            if(root.right!=null)
                findSecMinValue(root.right);
        }
    public int findSecondMinimumValue(TreeNode root) {
        findMinValue(root);
        findSecMinValue(root);
        if(SecMinFound)
        return SecMin;
            return -1;
    }
}
```