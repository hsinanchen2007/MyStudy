用的马拉车算法，累加每个位置可能参数的回文子串个数
```
class Solution {
public:
    int countSubstrings(string s) {
        string maStr = "$#";
        for (int i = 0; i < s.size(); i++) {
            maStr += s[i];
            maStr += "#";
        }

        vector<int> mp(maStr.size());
        int mx = 0, index = 0, res = 0;
        for (int i = 1; i < maStr.size(); i++) {
            mp[i] = i > mx ? 1 : min(mp[2 * index - i], mx - i);
            while (maStr[i + mp[i]] == maStr[i - mp[i]]) mp[i]++;
            if (mp[i] + i > mx) {
                mx = mp[i] + i;
                index = i;
            }
            res += mp[i] >> 1;
        }
        return res;
    }
};
```


![image.png](https://pic.leetcode-cn.com/4493be673267ef014a3bb185160eb9a7b3940a4abeb17605a5954b9d79f176b2-image.png)
