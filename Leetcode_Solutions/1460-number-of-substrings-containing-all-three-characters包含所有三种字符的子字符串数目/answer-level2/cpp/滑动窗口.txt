### 解题思路

滑动窗口枚举符合的前缀

### 代码

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int cnt = 0;
        unordered_map<char, int> window;
        
        while(r < n) {
            window[s[r]]++;
            while(r - l >= 2 && valid(window)) {
                cnt += n - r;
                window[s[l]]--;
                if(window[s[l]] == 0)
                    window.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
    
    bool valid(unordered_map<char, int>& w) {
        return w.count('a') > 0 && w.count('b') > 0 && w.count('c') > 0;
    }
};
```