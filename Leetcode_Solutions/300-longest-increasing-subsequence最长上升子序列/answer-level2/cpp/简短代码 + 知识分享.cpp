1. 第一种做法
定义dp[i]: `前ｉ个元素, 以第ｉ个元素结尾的最长上升子序列的长度`
dp[i]这个状态它可以从前面(1 ~ i - 1)这些状态转移过来, 时间复杂度为O(N ^ 2)

2. 第二种做法
定义dp[i]: `当从左往右扫一遍给定的输入数组时, 长度为ｉ时, 满足题目要求(上升), 的最小的值．`
显然dp是单调上升的, 所以我们让dp数组上升的缓慢(贪心)就能找到最长的上升子序列
因为是最小值, 所以用最大值初始化, 即下面代码里的std::fill()函数.

3. 总结
其实才是我想讲的东西, ~~dalao勿喷~~
`第一种做法很常见`, 然后它的状态定义里有`前i个元素...`这样的字样的状态定义, 像这样的状态, 转移的时候一般从第i个元素考虑, 常见的有背包问题, 考虑第i个元素取或不取等.
`第二种做法在竞赛(ACM / OI)里很常见`, 即题目所求的答案, 都是在dp数组的`下标里`(即大家口中说的`改变dp的对象`), 而不是常见的dp数组本身.

---
如果有兴趣, 可以去看看我在github上维护的一个项目, 系统的学习动态规划.
[我的动态规划项目](https://github.com/OFShare/Algorithm-challenger/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/README.md) ~~不要脸的推荐自己的项目~~, 欢迎star.
第一次在leetcode写题解, 希望大家喜欢. Written by OFShare on 2020-03-26 

```
class Solution {
public:
    static const int N = 1e6 + 5;
    int dp[N];

    int lengthOfLIS(vector<int>& nums) {
        const int INFF = 1e9;
        std::fill(dp, dp + N - 2, INFF);

        for (int i = 0; i < nums.size(); ++i) {
            auto it = std::lower_bound(dp + 1, dp + 1 + N - 2, nums[i]);
            *it = nums[i];
        }
        return std::lower_bound(dp + 1, dp + 1 + N - 2, INFF) - (dp + 1);
    }
};
```