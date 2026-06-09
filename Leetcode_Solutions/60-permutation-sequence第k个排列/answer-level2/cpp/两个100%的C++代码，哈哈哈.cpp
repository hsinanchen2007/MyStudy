思路就是从最高位逐步确定到最低位，每一步统计小于当前数的排列数。

```cpp
class Solution {
    int f(int n) {
        int ans = 1;
        for (int i = 1; i <= n; ++i) ans *= i;
        return ans;
    }
public:
    string getPermutation(int n, int k) {
        string ans = "";
        // 需要有一个计算阶乘的函数f
        if (n < 1 || k < 1 || f(n) < k) return ans;

        // 考虑n=5, k=16, k=k-1, 4!=4x3x2x1=24, 3!=6, 2!=2, 1!=1
        // k/(4!) = 0...15 == k, 表明这一位最小，没有比这位更新的，因此为1
        // k/(3!) = 2...3 < k, 表明除了已经使用的数外，还有2个数比自己小，因此为4，更新k=3
        // k/(2!) = 1...1, 表明除了已经使用的数外，还有1个数比自己小，因此为3，更新k=1
        // k/(1!) = 1...0, 表明除了已经使用的数外，还有1个数比自己小，因此为5，更新k=0
        // k==0 || n==0, 结束，最后一位只能是2(如果还剩多位，从小到大依次排列即可)，因此答案是：14352
        // 唯一的难点是如何记录已经使用的数，因为n有限，我们可以用一个bool数组记录之
        // 总共有这么多比自己小的：0x(4!)+2x(3!)+1x(2!)+1x(1!)=k, 注意k从1开始算起，因此一开始要-1
        --k;
        bool* flag = new bool[n+1]();
        for (int i = 1; i <= n; ++i) flag[i] = false;
        int n_c = n;

        while (k > 0 && n-- > 0) {
            int c = f(n);
            int a = k / c;
            int b = k % c;

            int num = 0, i = 1;
            while (num < a) if (!flag[i++]) ++num;
            while (flag[i]) ++i;

            // 此轮使用的数
            flag[i] = true;
            ans += (i + '0');

            // printf("%d/(%d!) = %d...%d, num=%d\n", k, c, a, b, i);

            // 更新k
            k = b;
        }
        for (int i = 1; i <= n_c; ++i) {
            if (!flag[i]) ans += (i + '0');
        }
        return ans;
    }
};
```

![image.png](https://pic.leetcode-cn.com/29147caf1af3407bbf54ef6ccaaa824be4eb18cd43d57261da893709755d172a-image.png)
