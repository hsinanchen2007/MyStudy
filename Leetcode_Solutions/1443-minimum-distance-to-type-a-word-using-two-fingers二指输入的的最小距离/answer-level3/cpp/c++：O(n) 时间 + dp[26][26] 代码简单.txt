# 思路
这道问题**反着过来思考**就比较好解决：
1. 字符串 str = "BIGCAKE"
2. 无论如何，当某只手指敲打完最后的字母 E 的时候，可以知道的是：
    - 人的一根手指肯定落在 E 上（很废话对吧）
    - 而另一只手指可能在键盘的任何一个地方(A-Z)。
3. 假设此时我们已经敲打下倒数第二个字母 K，即此时我们的手指分布为：
    - 一只手指落在 K
    - 另一只手指可能也在键盘的任何一个地方(A-Z)
4. 考虑从 K 到 E 的转移：
    - 设 dp[26][26] 分别表示**两只手指指向的两个字母到打完剩下的字母所需要的最短距离**
    - 很明显，从 E 到 K 转移，我们有两个选择，就是分别移动我们的两只手指，然后取其中能够达到最短的。
    - 那么可以得到 E 到 K 的转移：
```
dp[一只手指任意位置 pos][E] = min(选择1, 选择2)
选择1：移动第一只手指 = dp[E][K] + distance(pos 到 K 的距离)
选择2：移动落在 E 的手指 = dp[pos][K] + distance(E 到 K 的距离)
其中 pos ∈ [A, Z]，代码中遍历 A-Z 即可
```
很明显两根手指具有对称性，因此 dp 数组的第二个维度总是表示需要转移的下一个字母（例如上述的 K 总是在第二个维度上表示）。
我们只需要**从字符串结尾开始往前遍历**，就可以省略掉需要表示的当前敲打的字母了。

# 完整代码
```cpp
int dp[26][26];
int dis(int i, int j) {
    int x1 = i / 6, y1 = i % 6;
    int x2 = j / 6, y2 = j % 6;
    return abs(x1-x2) + abs(y1-y2);
}

int minimumDistance(string word) {
    memset(dp, 0, sizeof(dp));
    int n = word.size();
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            dp[j][word[i]-'A'] = min(dis(j, word[i+1] - 'A') + dp[word[i]-'A'][word[i+1]-'A'], dis(word[i] - 'A', word[i+1] - 'A') + dp[j][word[i+1] - 'A']);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; ++i) {
        ans = min(ans, dp[i][word[0] - 'A']);
    }
    return ans;
}
```

