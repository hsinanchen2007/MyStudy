# 暴力，顺便膜拜大神。
```
class Solution {
public:
    Solution() {
        for (int i = 0; i < 300; ++i) {
            yuan[i] = yuanId[i] = 0;
        }
        yuan['a'] = yuan['e'] = yuan['i'] = yuan['u'] = yuan['o'] = 1;
        yuanId['a'] = 0;
        yuanId['e'] = 1;
        yuanId['i'] = 2;
        yuanId['o'] = 3;
        yuanId['u'] = 4;
    }
public:
    int findTheLongestSubstring(string s) {
        const int len = s.size();
        vector <vector<int>> yuanCount;
        for (int i = 0; i < 5; ++i) {
            yuanCount.push_back(vector<int>(s.length()));
        }
        vector<int> yuanNext(len, -1);

        int firstYuan = len-1;
        bool flag = true;
        int fill = len;
        int max = 0;
        for (int i = 0; i < len; ++i) {
            int last = ((0 == i) ? 0 : i - 1);
            for (auto& c : yuanCount) {
                c[i] = c[last];
            }
            if (yuan[s[i]]) {
                firstYuan = i;
                ++yuanCount[yuanId[s[i]]][i];
                flag = yuanTrue(yuanCount, i);
            }
            if (flag) {
                max = i+1;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            yuanNext[i] = fill;
            if (yuan[s[i]]) {
                fill = i;
                firstYuan = i;
            }
        }
        for (int i = firstYuan + 1; i < len;) {
            if (i + max >= len) {
                break;
            }
            int end = i + max;
            while (end < len) {
                if (yuanTrue(yuanCount, end, i)) {
                    if (max < end - i + 1) {
                        max = end - i + 1;
                    }
                }
                if (end == len - 1) {
                    break;
                }
                end = yuanNext[end + 1] - 1;
            }
            if (yuan[s[i]]) {
                ++i;
            }
            else {
                i = yuanNext[i]+1;
            }
        }
        return max;

    }
private:
    int yuan[300], yuanId[300];
    inline
        bool o(int i) {
        return (i & 1) == 0;
    }
    
    bool yuanTrue(const vector<vector<int>>& yuanCount, int end, int start = 0) {
        for (auto& c : yuanCount) {
            int startCount = ((start == 0) ? 0 : c[start - 1]);
            if ((c[end] - startCount) & 1) {
                return false;
            }
        }
        return true;
    }
};
```