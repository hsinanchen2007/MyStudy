### 解题思路
什么叫状态压缩？其实就是用二进制数来表示动态规划状态转移过程中的状态。

什么时候应该状态压缩？状态压缩的题目，一般都会有非常明显的标志：如果你看到有一个参数的数值小于20，同时这道题目中有涉及到是否选取、是否使用这样的二元状态，那么这道题目很可能就是一道状态压缩的题目。

本题中的标志就是`target`的长度不超过15。于是，我们可以用一个二进制数表示`target`的每一位是否已经获取到。

后得到的状态对应的二进制数一定大于它的父状态。所以我们可以很自然地从`000...000`这一状态开始，一直遍历到`111...111`（目标状态）。对于每一个状态，我们遍历所有的`stickers`，看它能够更新出怎样的状态。

为了减少计算量，预处理得到了每一个`sticker`包含的每一种小写字母的个数。

### 优化前（568ms，331.2MB）

```cpp
#define INF 0x3f3f3f3f

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> dp(1 << 15, INF);
        int n = stickers.size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26));
        for (int i = 0; i < n; ++i)
            for (char c : stickers[i])
                cnt[i][c - 'a']++;
        
        dp[0] = 0;
        for (int i = 0; i < (1 << m); ++i) {
            if (dp[i] == INF)
                continue;
            for (int k = 0; k < n; ++k) {
                int nxt = i;
                vector<int> left(cnt[k]);
                for (int j = 0; j < m; ++j) {
                    if (nxt & (1 << j))
                        continue;
                    if (left[target[j] - 'a'] > 0) {
                        nxt += (1 << j);
                        left[target[j] - 'a']--;
                    }
                }
                dp[nxt] = min(dp[nxt], dp[i] + 1);
            }
        }
        return dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1];
    }
};
```

### 如何优化？

上面的代码通过了测试，但时间和空间消耗均无法让人满意。让我们思考一下问题出在哪里。

考虑有`hello`和`world`，目标状态是`helloworld`。我们从`0000000000`开始时，既考虑了使用`hello`，也考虑了使用`world`。这样就更新出了`1111100000`和`0000011111`两个状态。我们会发现，它们其实是殊途同归的。第一次选`hello`，第二次就要选`world`；第一次选`world`，第二次就要选`hello`。由于我们只需要计算使用贴纸的数量，先后顺序其实并不重要，这两个状态其实是重复的。

如何消除这一重复？我们可以增加一重限制。每次从当前状态开始更新时，我们只选择包含了当前状态从左边开始第一个没有包含的字母的那些贴纸。比如说在上面的例子中，在`0000000000`状态下，我们将只会选择`hello`，不会选择`world`（没有包含`h`）。这样就去除了顺序导致的重复状态。

为了实现这一优化，我们预处理得到了`can`数组，记录包含每一个字母的贴纸序号。

### 优化后（68ms，41MB）

```cpp
#define INF 0x3f3f3f3f

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> dp(1 << 15, INF);
        int n = stickers.size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26));
        vector<vector<int>> can(26);
        for (int i = 0; i < n; ++i)
            for (char c : stickers[i]) {
                int d = c - 'a';
                cnt[i][d]++;
                if (can[d].empty() || can[d].back() != i)
                    can[d].emplace_back(i);                
            }
        
        dp[0] = 0;
        for (int i = 0; i < (1 << m) - 1; ++i) {
            if (dp[i] == INF)
                continue;
            int d;
            for (int j = 0; j < m; ++j) {
                if (!(i & (1 << j))) {
                    d = j;
                    break;
                }
            }
            d = target[d] - 'a';
            for (int k : can[d]) {
                int nxt = i;
                vector<int> left(cnt[k]);
                for (int j = 0; j < m; ++j) {
                    if (nxt & (1 << j))
                        continue;
                    if (left[target[j] - 'a'] > 0) {
                        nxt += (1 << j);
                        left[target[j] - 'a']--;
                    }
                }
                dp[nxt] = min(dp[nxt], dp[i] + 1);
            }
        }
        return dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1];
    }
};
```
可以看到，优化的效果非常明显。