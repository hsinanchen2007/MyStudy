```
/**
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项* 数字的和。也就是：
 *     F(0) = 0,   F(1) = 1
 *     F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 *     给定 N，计算 F(N)。
 */
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

// 递归解法
int fib_1(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    return fib_1(N - 1) + fib_1(N - 2);
}

int helper(vector<int> &store, int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    if (store[N] == 0) {
        store[N] = helper(store, N - 1) + helper(store, N - 2);
    }

    return store[N];
}

// 带“备忘录”的递归
int fib_2(int N) {
    vector<int> store(N + 1, 0);
    return helper(store, N);
}

// 动态规划
int fib_3(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

// 优化动态规划，空间复杂度O（1）
int fib_4(int N){
    if (N == 0) return 0;
    if (N == 1) return 1;

    int pre_1 = 0, pre_2 = 1;
    int curr;
    for(int i = 2; i <= N; ++i){
        curr = pre_1 + pre_2;
        pre_1 = pre_2;
        pre_2 = curr;
    }
    return curr;
}

int main() {
    clock_t start = clock();
    fib_1(30);
    clock_t end = clock();
    cout << "递归时间：" << (end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    fib_1(30);
    end = clock();
    cout << "带备忘录的递归时间：" << (end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    fib_1(30);
    end = clock();
    cout << "动态规划的时间：" << (end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    fib_1(30);
    end = clock();
    cout << "优化后的动态规划时间：" << (end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
```
