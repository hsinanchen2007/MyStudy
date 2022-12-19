```cpp
class Solution {
public:
    string sortString(string s) {
        int cnt[26] = { 0 };
        for (auto ch : s) ++cnt[ch - 'a'];

        string ans;
        int n = 0, N = s.size();
        auto appendChar = [&](int i) {
            if (cnt[i]) {
                ans.push_back(i + 'a');
                --cnt[i];
                ++n;
            }
        };

        while (n <  N) {
            for (int i = 0; i < 26; ++i) appendChar(i);
            for (int i = 25; i >= 0; --i) appendChar(i);
        }

        return ans;
    }
};
```