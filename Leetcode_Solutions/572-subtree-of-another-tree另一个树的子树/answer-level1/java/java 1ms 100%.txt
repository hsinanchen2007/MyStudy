### 思路
1. 首先，先求二叉树`t`的节点个数`tCount`,为什么要求这个呢？主要是为了遍历`s`的过程中可以减少子树之间的比较次数；
2. 接着，遍历二叉树`s`，在遍历过程中做两件事：
     - 计算二叉树`s`的以每个节点为根节点的子树的节点个数，假设为`count`；
     - 若`count == tCount`，那么就可以判断执行`isSame(subS, t)`方法判断当前子树是否与`t`相等，若找到相等的，则将全局变量`isFoundSame = true`,然后再递归函数的头部对`isFoundSame`进行判断，如果为`true`，则立马返回，也就是告诉递归函数 **“我已经找到相等了，请快速结束递归”**。
<br/>
```java
     // 判断两棵二叉树是否相等
     private boolean isSame(TreeNode root1, TreeNode root2) {
        if (root1 == null) {
            return root2 == null;
        }

        if (root2 == null) {
            return false;
        }

        return root1.val == root2.val && isSame(root1.left, root2.left) && isSame(root1.right, root2.right);
    }

    private boolean isFoundSame = false;
    private int tCount;

    // 递归计算二叉树s每棵子树的节点数，并同时寻找是否有子树与t相等
    private int calcCount(TreeNode root, TreeNode t) {
        if (isFoundSame) {
            return 0;
        }

        if (root == null) {
            return 0;
        }

        int count = calcCount(root.left, t) + calcCount(root.right, t) + 1;
        if (count == tCount && isSame(root, t)) {
            isFoundSame = true;
            return 0;
        }
        return count;
    }

    // 计算二叉树t的节点个数
    private int calcTCount(TreeNode root) {
        return root == null ? 0 : calcTCount(root.left) + calcTCount(root.right) + 1;
    }

    public boolean isSubtree(TreeNode s, TreeNode t) {
        tCount = calcTCount(t);
        calcCount(s, t);
        return isFoundSame;
    }
```