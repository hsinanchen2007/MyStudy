### 解题思路
卡塔兰公式， 看完题解之后思路比较清晰

### 代码
```java
class Solution {
    public int numTrees(int n) {

        // 卡塔兰公式
        // Cn = c0 * c(n-1) + c1 * c(n-2) + ... + c(n-1)*c(0)
        // c0 = c1 = 1;
        // 令f(x) 表示以x为根节点二叉搜索树的种数
            // f(x) = 左子树g(x-1) 与 右子树g(x+1)的笛卡尔积
        // 令g(x) 表示1...x组成二叉搜索树种数
        // g(7) = { [f(1) = g(0) * g(6)] + [f(2) = g(1) * g(5)] + ... + [f(7) = g(6) * g(0)] }
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        int[] rs = new int[n + 1];
        rs[0] = rs[1] = 1;
        rs[2] = 2;
        rs[3] = 5;
        for (int i = 4; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                rs[i] += rs[j-1] * rs[i-j];
        return rs[n];
    }
}
```