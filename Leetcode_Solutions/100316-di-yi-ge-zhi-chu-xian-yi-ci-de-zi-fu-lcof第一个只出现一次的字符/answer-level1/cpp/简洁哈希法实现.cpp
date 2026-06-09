### 解题思路
直接开大小为26（若考虑全ASCII码范围则256）的数组来统计访问情况

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size() == 0) return ' ';
        vector<int> counter(26, 0);
        for(auto ch:s)
            counter[ch - 'a'] += 1;
        for(auto ch:s)
            if(counter[ch - 'a'] == 1)
                return ch;
        return ' ';
    }   
};
```
### 复杂度
时间复杂度O(n)
空间复杂度O(1)
