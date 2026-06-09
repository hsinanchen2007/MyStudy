### 解题思路
这道题在比赛时，我的求解思路是正确的，但是在最后一个测试用例超出时间限制了。看来还是自己分析不够。后来看了评论马上就反应过来了，如果具有长度`maxSize`的子串取得了答案，那么该子串的前`minSize`个字符构成的子串亦是答案，所以我们只需考虑所有具有`minSize`长度的子串。我们可以在`O(n*minSize)`的复杂度内获取所有这样的子串。

还有两件事需要做，一是判断子串是否至多包含`maxLetters`个字符，另一个是我们用一个哈希表统计符合条件的子串出现的次数，并更新最终的答案。

### 代码

```cpp
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0;
        int n = s.size();
        unordered_map<string, int> m;
        int cnt[26] = {0};
        for (int i = 0; i <= n - minSize; i++) {
            string t;
            int letters = 0;
            memset(cnt, 0, sizeof(cnt));
            int k = 0;
            while (k < minSize) {
                char ch = s[i + k];
                t += ch;
                cnt[ch - 'a']++;
                if (cnt[ch - 'a'] == 1) letters++;
                k++;
            }
            if (letters <= maxLetters) {   
                ++m[t];
                if (m[t] > res) res = m[t];
            }
        }
        return res;
    }
};
```