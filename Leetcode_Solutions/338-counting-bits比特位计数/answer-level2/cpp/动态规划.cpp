`/*
     动态规划
     要找到规律，找到状态转移函数
     思考：
     对于每一个数 x 的二进制表示，我们将它左移之后，在后面补上 0 或者 1 得到 x1，x2，观察其值与 x 的关系
     对于补 0，x1 = 2 * x；对于 x2 = 2 * x + 1，而 x1 的二进制位与 x 相同，x2 的二进制位比 x 多 1
     P(x)表示 x 的二进制表示中的 1 的个数，得到：
     P(x) = P(x/2) + (x mod 2)，x mod 2 即表示是否加了左移之后是否加了 1
     */
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i / 2] + (i & 1);
        }
        
        return res;
    }`