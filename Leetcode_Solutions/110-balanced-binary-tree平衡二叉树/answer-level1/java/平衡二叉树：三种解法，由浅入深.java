# 思路1: 简单粗暴，先判断左右分支是否平衡二叉树，然后判断左右分支的深度差即可

```
public boolean isBalanced(TreeNode root) {
        //1.判空
        if (root == null) {
            return true;
        }
        //2. 左右先是，左右的高度差不超过2
        return isBalanced(root.left) && isBalanced(root.right) && Math.abs(getDepth(root.left) - getDepth(root.right)) < 2;
    }

    private int getDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(getDepth(root.left), getDepth(root.right)) + 1;
    }
```

# 思路2: 思路1的问题在于子分支的高度计算太冗余，从底向上，除了顶节点，其他节点的高度都被重复计算了。
- 故，很自然想到，判断分支是否平衡的同时，记录下分支的高度即可；
- 然后就可以想到构造一个方法，返回对象包含boolean和深度即可。官方题解2就是这么做的。
- 还有一种投机的方法，可以把深度记录在val里，反正这个值在这个题里无用。

```
 public boolean isBalanced(TreeNode root) {
        //优化思路：消除depth计算冗余
        //1. 判空，并且记录高度
        if (root == null) {
            return true;
        }
        if (root.left == null && root.right == null) {
            root.val = 1;
            return true;
        }
        //2. 先判断左右分支
        if (!isBalanced(root.left) || !isBalanced(root.right)) {
            return false;
        }
        //3. 计算左右分支高度，同时计算父节点的高度
        int leftDepth = root.left == null ? 0 : root.left.val;
        int rightDepth = root.right == null ? 0 : root.right.val;
        root.val = Math.max(leftDepth, rightDepth) + 1;
        //4. 判断高度差即可
        return Math.abs(leftDepth - rightDepth) < 2;
    }
```

# 思路3: 思路2我自己的解法不是很通用。然后看到了楼下 [@fastpass](/u/fastpass/)的思路，很好玩
- 既然一个方法只能返回一个值：isBalanced()只能返回boolean，getDepth()只能返回depth；
- 那么可不可以用一个返回值来映射出另一个返回值呢？
- boolen映射depth显然不能；
- depth显然是可以的：平衡二叉树返回正常高度即可，非平衡二叉树返回-1即可

```
public boolean isBalanced(TreeNode root) {
          //获取平衡二叉树的高度，如果不平衡则返回-1
          return getBalancedDepth(root) != -1;
    }

    private int getBalancedDepth(TreeNode root) {
        //1. 空，深度为0
        if (root == null) {
            return 0;
        }
        //2. 分支同时为空，深度为1
        if (root.left == null && root.right == null) {
            return 1;
        }
        //3. 获取左右分支的高度
        int leftDepth = getBalancedDepth(root.left);
        int rightDepth = getBalancedDepth(root.right);
        //4. 先判断左右分支是否平衡
        if (leftDepth == -1 || rightDepth == -1) {
            return -1;
        }
        //5. 再判断高度差
        if (Math.abs(leftDepth - rightDepth) >= 2) {
            return -1;
        }
        //6. 返回平衡二叉树的高度
        return Math.max(leftDepth, rightDepth) + 1;
    }
```


