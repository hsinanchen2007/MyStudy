```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if (s.size() == 0) 
            return ' ';
        // int map[256] = {0};
        unordered_map<char, int > map;
        for (auto a : s)
            map[a] ++;
        for (auto a : s)
            if (map[a] == 1)
                return a;
        return ' ';
    }
};
```