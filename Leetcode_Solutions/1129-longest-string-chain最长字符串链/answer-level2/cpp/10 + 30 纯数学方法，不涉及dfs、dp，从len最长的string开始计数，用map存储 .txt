### 解题思路
mStrChain[s] = max(mStrChain[s], mStrChain[ls] + 1);

1. string删除特定位置字符，10行代码2处致命错误也是可以;
2. 这个最长链起始可以从任一位置开始
3. 判断是否是前身string有更好的方法吗？
    bool judge(const string &prefix, const string &target){
        vector<int> count(26,0);
        for(auto val : target) count[val-'a']++;
        for(auto val : prefix){
            count[val-'a']--;
            if(count[val-'a']<0) return false;
        }
        return true;
    }

### 代码

```cpp
class Solution {
public:
    bool IsPre(string s1, string s2) {
        int len = s2.size();
        for (int i = 0; i < len; i++) { // for (int i = 0; i < s2.size(); i++) {
            string ss2 = s2;
            string tmp = ss2.erase(i, 1); // RESET!!! s2 = s2.erase(i, 1)
            if (s1 == tmp) {
                return true;
            }
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> m;
        int minLen = INT_MAX;
        int maxLen = INT_MIN;
        map<string, int> mStrChain;
        for (auto s : words) {
            int len = s.size();
            m[len].push_back(s);
            minLen = min(len, minLen);
            maxLen = max(len, maxLen);
            mStrChain[s] = 1;
        }
        int ans = 1;
        for (int i = maxLen; i >= minLen; i--) {
            if (m[i].size() == 0) {
                continue;
            }
            if (i == maxLen) {
                continue;
            }
            for (auto s : m[i]) {
                for (auto ls : m[i + 1]) {
                    if (IsPre(s, ls) == false) {
                        continue;
                    }
                    mStrChain[s] = max(mStrChain[s], mStrChain[ls] + 1);
                    ans = max(ans, mStrChain[s]);
                }
            }
        }
        return ans;
    }
};
```