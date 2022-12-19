### 解题思路
使用递归的关键是要明白：递归函数的作用是什么，从宏观的角度去理解递归，不用太在意递归是如何进行调用的。
如果想具体的进一步了解，可以使用小的数据量进行手动的推导，深度的理解递归中的具体调用。

递归有两个重要的组成部分：
1. 递归终止条件： 用来跳出递归，写好递归先从简单的入手，弄清楚最简单的情况，就可以写出终止条件
2. 具体实现：实现递归函数的功能

本题来说：
二叉树的最大深度，二叉树是具有天生的递归的优势，看到题目首先就想到使用递归来进行实现。
递归函数的作用：计算二叉树的深度。
递归终止条件：node == null
为了更好的理解，创建了一个方法进行辅助调用。
public int a(TreeNode root,int height)  height记录深度
递归实现：给定一个root，计算深度，就需要取root中左右子树的深度的最大值，递归函数的作用就是计算深度，理解函数的作用，由此产生递归。


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
        return a(root,0);
    }

    public int a(TreeNode root,int height){
        if(root == null){
            return height;
        }
        int leftHeight = a(root.left,height+1);
        int rightHeight = a(root.right,height+1);
        return Math.max(leftHeight,rightHeight);
    }
}
```