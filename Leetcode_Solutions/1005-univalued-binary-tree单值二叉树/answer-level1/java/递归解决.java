这道题的递归我觉得挺有意思的，和我之前写过的不同，以前写的递归返回值都没有布尔类型的，突然来了这么一个，一下子倒是没想得出来，下面就分享一下我的解题思路吧！
首先要找出最小的递归体，即只有一个根节点和两个子节点，要判断它是不是单值二叉树就很简单了：`root.val==root.left.val&&root.val==root.right.val`即可，就是
三个节点的值都相等，那下面就要延伸到子节点的字节点了。就一句话，根节点和第二层子节点是单值二叉树，子节点和子节点的子节点是单值二叉树，就是把子节点下的二叉树
看成一个整体，而这个整体就是我们递归调用自己的地方，上代码：
```
public boolean isUnivalTree(TreeNode root) {
        if(root==null)return true;
        if(isUnivalTree(root.left)&&isUnivalTree(root.right)){//把子节点下的二叉树包括自己看成一个整体作为一个子节点，左右节点均为单值二叉树，则开始与根节点对比，否则直接return false
             if(root.left==null&&root.right==null) return true;//左右节点null，说明是叶子节点，叶子节点为根节点，没有左右节点比较（可以看成只有一个节点的二叉树），本身就是单值二叉树
             if(root.left==null) return root.val==root.right.val;//左节点为null，只需要比较根节点和右子节点
             if(root.right==null) return root.val==root.left.val;//右节点为null，只需要比较根节点和左子节点
             return (root.val==root.left.val&&root.val==root.right.val);//都不为空，就两两比较
        }
          return false;
    }
```
递归这种东西挺难说清的，就算是我自己写的都不能完整地理清楚整个思路，只是大概清楚要这么做，递归的题记住一点：当前的方法已经能解决最小数据规模的问题了，我只要不断调用就行