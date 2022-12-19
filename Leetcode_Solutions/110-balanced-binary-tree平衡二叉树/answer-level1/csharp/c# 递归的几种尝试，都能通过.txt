面对此类二叉树的不同角度的问题，经常用到递归。本人经常会想，是否递归也可以有不同的写法，效率大概也不同。

其他广度遍历等非递归方式，目前还没评估是否性能优秀。后面会学习。

下面给代码参考：

```
/*
 * @lc app=leetcode.cn id=110 lang=csharp
 *
 * [110] 平衡二叉树
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool IsBalanced(TreeNode root) {
        //Simpler implememtation
        if(root == null)
        {
            return true;
        }
        if(CalDepth(root) == -1)
        {
            return false;
        }
        
        return true;
    }

    private int CalDepth(TreeNode node)
    {   
        int left = 0;
        int right = 0;

        if(node == null)
        {
            return 0;
        }

        if(node.left != null)
        {
            left = CalDepth(node.left);
        }
        if(node.right != null)
        {
            right = CalDepth(node.right);
        }

        if(left == -1 || right == -1)
        {
            return -1;
        }

        if(left - right > 1 || left - right < -1)
        {
            return -1;
        }

        return Math.Max(left, right) + 1;
    }

    //     if(root == null)
    //     {
    //         return true;
    //     }

    //     int leftDepth = 0;
    //     int rightDepth = 0;
    //     if(root.left != null)
    //     {
    //         leftDepth = GetDepth(root.left);
    //     }
    //     if(root.right != null)
    //     {
    //         rightDepth = GetDepth(root.right);
    //     }
        
    //     if(Math.Abs(leftDepth - rightDepth) > 1)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         return IsBalanced(root.left) && IsBalanced(root.right);
    //     }
    // }

    // private int GetDepth(TreeNode node)
    // {
    //     if(node == null)
    //     {
    //         return 0;
    //     }

    //     int left = GetDepth(node.left);
    //     int right = GetDepth(node.right);

    //     return Math.Max(left, right) + 1;
    // }
}


```
