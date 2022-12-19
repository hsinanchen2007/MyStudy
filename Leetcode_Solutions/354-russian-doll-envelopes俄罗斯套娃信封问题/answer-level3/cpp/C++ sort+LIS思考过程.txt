自己硬着头皮想了一个多小时才想到。

首先如果这道题改为长度和高度大于等于当前信封可以塞进去，那么这道题就好做多了。区别在于长度相同的情况。

# 1.朴素想法
最开始先想一个$O(n^2)$的想法：
先按宽(或者高)排序，然后dp[i]表示以i结尾的最长套娃，每次更新dp[i]取dp[0~i-1]里能套上的最大值更新。
AC 680ms
```c++
bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(n, 0);
        int max_length = 0;
        for(int i = 0; i < n; i++){
            int res = 1;
            for(int j = i - 1; j >= 0; j--){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    res = max(res, dp[j] + 1);
            }
            max_length = max(max_length, res);
            dp[i] = res;
        }
        return max_length;
    }
};
```
# 2.LIS
瓶颈出现在每次更新dp[i]需要计算dp[0~i-1]，使复杂度上升到了O(n2)。
假设我们开始按宽度从小到大排序。联想到300题的最长上升子序列，将dp[i]的状态改变为长度为i的套娃的高。

直接这么做会出现一个问题，在300题中，一维数组只用保存一个数字，现在需要考虑两个数，因此直接用一维数组丢失的信息是该套娃最后一个信封的宽。因为我们的循环顺序是宽从小到大，冲突发生在如果有若干个套娃的宽度相同，我们在循环中会依次遍历到这几个套娃。

假设有n个信封的宽度相同，这n个信封分别是$a_1, a_2, a_3,...,a_n$。当我们计算完$a_1$时，$a_1$会更新dp数组，如果$a_2$的高度比$a_1$大，我们的dp数组丢失了以$a_1$为最外层信封的套娃的宽度，直接比较就会让$a_2$套在$a_1$外面产生错误。

从上面的分析我们就能得出，如果同一个宽度下高度是以降序排列的，我们就不用关心宽度问题了(因为后遍历到的信封一定无法套到前面信封上)。

AC 32ms
```c++
bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(n + 1, -1);
        int max_length = 0;
        for(int i = 0; i < n; i++){
            int h = envelopes[i][1];
            auto ins_iter = lower_bound(dp.begin(), dp.begin() + max_length + 1, h);
            int len = max(1, (int)(ins_iter - dp.begin()));
            max_length = max(len, max_length);
            dp[len] = h;
        }
        return max_length;
    }
};
```