嫌前面的分析啰嗦的话可以直接看最后的代码，还是挺好理解的。


有了打家劫舍I(No198)和打家劫舍II(No213)的铺垫，这类题目的套路基本上是清楚了，一定是用动态规划。前两题是在一维线性的条件下，动态规划的状态和转移方程很容易得出。

以打家劫舍I(No198)为例，设dp[i]为偷盗前i家获得的最大金额

边界条件dp[0]=a[0],dp[1]=max(a[0],a[1])

因为相邻的两家不能同时偷，第i家如果偷的话获得的金额是第i家的金额加上前i-2家获得的最大金额，即a[i]+dp[i-2],第i家如果不偷的话，获得的金额是前i-1家获得的最大金额，即dp[i-1]

于是状态转移方程就是dp[i]=max(a[i]+dp[i-2],dp[i-1])

当然，打家劫舍II(No213)增加了尾位相连的条件也很容易解决，无非就是在第一题的基础上增加了“偷了第一家就不能偷最后一家”的条件，那么大不了就循环两次，在偷第一家的情况下得到一个最大金额，在不投第一家的情况下得到一个最大金额，然后取最大值。



本题的数据结构改成了树形，之前我们的动态规划是自顶向下的，在这个问题上我们采用自底向上的方法，遍历一遍树就能得到最优解，我们采用这样的思路：

**假设树的每一个根节点保存的数据改写成这个根节点及它下面的节点能获得的最大金额，那么：**

**当前根节点=max(下一层根节点的和，下下层根节点的和+当前根节点的值)**

那么我们用递归的方法来写，每次都把最优解放到根节点上给上一层用。代码如下：
```
    public int rob(TreeNode root) {
        int sum1 = 0;//在不取下一层，而取下下层的情况下获得的最大金额
        int sum2 = 0;//在取下一层的节点的情况下获得的最大金额

        if (root == null) {
            return 0;
        }
        if (root.left != null) {
            sum2 += rob(root.left);
            if (root.left.left != null) {
                sum1 += rob(root.left.left);
            }
            if (root.left.right != null) {
                sum1 += rob(root.left.right);
            }
        }
        if (root.right != null) {
            sum2 += rob(root.right);
            if (root.right.left != null) {
                sum1 += rob(root.right.left);
            }
            if (root.right.right != null) {
                sum1 += rob(root.right.right);
            }
        }

        root.val = Math.max(sum2, root.val + sum1);
        return root.val;
    }
```

结果发现了一个问题，假设树有4层，我们在计算第1层时需要计算第2、3层的结果，在计算第2层的时候需要计算第3、4层的结果，第3层被计算了2遍，而第一遍的时候已经把它的值给改了，所以结果当然就错了。

找到问题之后剩下的就比较容易了，被修改过的节点就直接返回，不要再计算了。如果数据结构可以随意更改的话就很简单，我在树的结构里再加一个boolean变量，当这个节点被修改后就置为true，看到了true以后就直接返回不计算了。但是树的结构当然是不能改变的，所以我们从题目的限制出发，我们发现每一家的金额肯定都大于0，所以在修改节点的时候我们加一个负号来标记他就可以了，每一层递归返回的是该节点的相反数，于是在上面的代码基础上稍作修改（最后两行加了负号，开头增加一个条件判断）：
```
    public int rob(TreeNode root) {
        int sum1 = 0;//在不取下一层，而取下下层的情况下获得的最大金额
        int sum2 = 0;//在取下一层的节点的情况下获得的最大金额

        if (root != null && root.val < 0) {
            return -root.val;
        } else if (root == null) {
            return 0;
        }
        if (root.left != null) {
            sum2 += rob(root.left);
            if (root.left.left != null) {
                sum1 += rob(root.left.left);
            }
            if (root.left.right != null) {
                sum1 += rob(root.left.right);
            }
        }
        if (root.right != null) {
            sum2 += rob(root.right);
            if (root.right.left != null) {
                sum1 += rob(root.right.left);
            }
            if (root.right.right != null) {
                sum1 += rob(root.right.right);
            }
        }

        root.val = -Math.max(sum2, root.val + sum1);
        return -root.val;
    }
```

时间复杂度O(n)，最终结果打败99.81%的java提交

（2020.2.18号修改了错误的状态转移方程的说明）
