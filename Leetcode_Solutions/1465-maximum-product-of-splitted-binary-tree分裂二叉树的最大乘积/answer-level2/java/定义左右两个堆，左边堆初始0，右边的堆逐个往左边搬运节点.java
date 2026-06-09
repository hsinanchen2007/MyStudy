首先需要知道的一个数学结论，两数和固定时，什么时候两数积最大————答案是两数差值越小积越大。接下来利用这个结论解题。

首先定义左右两个堆，左边堆初始为空，节点值总和为0，右边堆初始即为root，节点值总和为全部的值。这时候，左边堆和小于右边堆，根据前面结论理应从右边堆往左边堆搬运节点，接下来是如何搬运的问题了。

右边堆是个二叉树，搬运节点有两种可能的搬法：
1. 将右边堆的根节点和右边子树一起合并到左边堆
2. 将右边堆的根节点和左边子树一起合并到左边堆
如下所示是右边堆，可以自行想象一下
```
      rightRoot
       /    \
      /      \
rightLeft  rightRight
```

最后还有一个问题，何时结束————当左边堆第一次比右边堆大的时候，就可以结束了，并且要计算这时候左右两边的差值作为最终答案的一个可能性。


接下来就可以编码了，为了降低运行时间，预先将原本树节点上的值改变一下，由存储当前节点的值改为存储以当前节点为根节点的树的所有节点值的总和。

编码如下
```java
    public int maxProduct(TreeNode root) {
        initSum(root);
        
        TreeNode rightRoot = root;
        
        int total = root.val;
        int lc = 0;
        int rc = total;
        
        int rightInMax = getRightInMax(root, lc, rc);
        
        int leftInMax = total - rightInMax;
        
        int m = 1000_000_000 + 7;
        
        long r = (((long) rightInMax) * leftInMax) % m;
        return (int) r;
    }
        
    private int getRightInMax(TreeNode rightRoot, int lc, int rc) {
        if (rightRoot == null) {
            return 0;
        }
        
        int divide = Math.abs(lc - rc);
        int rightInMax = rc;
        
        int left = rightRoot.left != null ? rightRoot.left.val : 0;
        int right = rightRoot.right != null ? rightRoot.right.val : 0;
        int val = rightRoot.val - left - right;
        
        int lc0 = lc + val;
        
        int d1 = Math.abs(lc0 + left - right);
        if (d1 < divide) {
            divide = d1;
            rightInMax = right;
        }
        
        
        int d2 = Math.abs(lc0 + right - left);
        if (d2 < divide) {
            divide = d2;
            rightInMax = left;
        }
        
        if (lc0 + left < right) {
            int r3 = getRightInMax(rightRoot.right, lc0 + left, right);
            int d3 = Math.abs(lc + rc - r3 - r3);
            if (d3 < divide) {
                divide = d3;
                rightInMax = r3;
            }
        }
        
        if (lc0 + right < left) {
            int r4 = getRightInMax(rightRoot.left, lc0 + right, left);
            int d4 = Math.abs(lc + rc - r4 - r4);
            if (d4 < divide) {
                divide = d4;
                rightInMax = r4;
            }
        }
        
        return rightInMax;
    }

    private void initSum(TreeNode root) {
        if (root == null) {
            return;
        }
        initSum(root.left);
        initSum(root.right);
        int sum = root.val;
        if (root.left != null) {
            sum = root.left.val + sum;
        }
        if (root.right != null) {
            sum = root.right.val + sum;
        }

        root.val = sum;
    }
```
------------------

------------------
重新考虑了一下，其实这就是一个二叉树裁剪问题，无论如何裁剪，必然有其中一边是其中一个节点构成的一棵子树，只需要找到值最接近1/2总和的节点。修改后代码如下
```java
    public int maxProduct(TreeNode root) {
        initSum(root);
        
        int rightInMax = getRightInMax(root, (float) root.val / 2);
        int leftInMax = root.val - rightInMax;
        int m = 1000_000_000 + 7;
        
        long r = (((long) rightInMax) * leftInMax) % m;
        return (int) r;
    }
    
    private int getRightInMax(TreeNode root, float target) {
        float divide = Math.abs(target - root.val);
        int rightInMax = root.val;

        if (root.val < target) {
            return rightInMax;
        }
        if (root.right != null) {
            int r1 = getRightInMax(root.right, target);
            float d1 = Math.abs(target - r1);
            if (d1 < divide) {
                divide = d1;
                rightInMax = r1;
            }
        }
        if (root.left != null) {
            int r2 = getRightInMax(root.left, target);
            float d2 = Math.abs(target - r2);
            if (d2 < divide) {
                divide = d2;
                rightInMax = r2;
            }
        }
        return rightInMax;
    }

    private void initSum(TreeNode root) {
        if (root == null) {
            return;
        }
        initSum(root.left);
        initSum(root.right);
        int sum = root.val;
        if (root.left != null) {
            sum = root.left.val + sum;
        }
        if (root.right != null) {
            sum = root.right.val + sum;
        }

        root.val = sum;
    }
```


两个代码运行时间都是7ms，如果没有提前停止的优化，运行时间大概在12ms