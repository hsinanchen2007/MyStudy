### 解题思路
0、防御编程，边界条件判断
1、先统计
2、再求解统计数的最大公约数，
3、判断是否大于等于2 
4、空间负杂度O(N), 时间复杂度O(N)

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) {
            return false;
        }

        unordered_map<int, int> und_map;

        for (auto n : deck) {
            auto ret =  und_map.emplace(n, 1);
            if (ret.second == false) {
                und_map[n]++;
            }
        }
        
        int ans = und_map.begin()->second;
        for (auto p : und_map) {
            ans = gcd<int, int>(ans, p.second);
        }
        return (ans >= 2);

    }

};
```