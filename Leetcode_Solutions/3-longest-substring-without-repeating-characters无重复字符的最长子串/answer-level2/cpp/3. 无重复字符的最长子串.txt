### 解题思路
hash_map 

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int res = 0, start = 0, length = 0;
        unordered_map<char, int> mymap;
        for(int i = 0;  i < len; i++){
            if(mymap.find(s[i]) != mymap.end() && mymap[s[i]] >= start){
                start = mymap[s[i]] + 1;
                length = i - start;
            }
            mymap[s[i]] = i;
            length++;
            res = max(res, length);
        }
        return res;
    }
};
```