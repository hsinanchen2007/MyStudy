### 解题思路
用哈希图来记录每个字符最后一次出现的位置，如果该位置在start point 之后， 则重置start point。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, -1);
        int start = 0, maxsub = 0;

        for(int end = 0; end < s.length(); end++){
            // cout << v[s[end]] << endl;
            if(v[s[end]] >= start) start = v[s[end]] + 1;
            v[s[end]] = end;
            maxsub = max(maxsub, end - start + 1);
            // cout << start << " " << end << " " << maxsub << endl;
         }
         return maxsub;
    }
};
```