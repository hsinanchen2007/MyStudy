由题意可知：一个节点的最大直径 = 它左树的高度 +  它右树的高度

因此本题遍历每个节点，找出所有节点中的直径的最大值即可。

更多关于树的递归的题可以看[此文](https://blog.csdn.net/reed1991/article/details/53759801)

刚开始这么写的
```
private int max = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = depth(root.left);
        int right = depth(root.right);
        max = max > (left + right) ? max : (left + right);
        diameterOfBinaryTree(root.left);
        diameterOfBinaryTree(root.right);
        return max;

    }

    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(depth(root.left), depth(root.right)) + 1;
    }
```
但是发现效率不高。仔细想了一下，造成效率不高的原因主要是这么写其实进行了两次遍历。
其实我们在求每个节点的高度的时候，顺带就可以求出其直径，第二种方式代码如下。
```
 public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return max;
    }

    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftDep = depth(root.left);
        int rightDep = depth(root.right);
        max = max > (leftDep + rightDep) ? max : (leftDep + rightDep);
        return (leftDep > rightDep ? leftDep : rightDep) + 1;
    }
```
