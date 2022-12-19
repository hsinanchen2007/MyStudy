```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cache[26] = { 0 };
        for (auto ch : chars)
            ++cache[ch - 'a'];

        int res = 0;
        for (auto w : words) {
            int cnt[26];
            copy(begin(cache), end(cache), begin(cnt));

            bool breakFlag = 0;
            for (auto ch : w) {
                if (cnt[ch - 'a'] == 0) {
                    breakFlag = 1;
                    break;
                }
                --cnt[ch - 'a'];
            }
            if (breakFlag != 1)res += w.size();
        }
        return res;
    }
};
```