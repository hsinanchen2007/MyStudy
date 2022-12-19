![image.png](https://pic.leetcode-cn.com/b83eecee2c77f1761cc51c53894f73b89bc8134cb39b6cd3d4b3909a5795e089-image.png)

``` c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {  
        if (s1.size() > s2.size()) return false;
        vector<int> dict(26, 0), window(26,0);
        for (auto ch:s1) {
            dict[ch - 'a']++;
        }
        int i = 0;
        int num = s1.size(), len = s1.size();
        while (i < len) {
            int ch = s2[i] - 'a';
            window[ch]++;
            if (dict[ch] > 0 && window[ch] <= dict[ch]) num--;
            i++;
        }
        if (num == 0) return true;
        while (i < s2.size()) {
            int ch = s2[i] - 'a';
            window[ch]++;
            if (dict[ch] > 0 && window[ch] <= dict[ch]) num--;
            ch = s2[i - len] - 'a';
            if (dict[ch] > 0 && window[ch] <= dict[ch]) num++;
            window[ch]--;
            if (num == 0) return true;
            i++;
        }
        return false;
    }
};
```
