### 解题思路
* 为什么求解相邻的最大公约数可以通过？

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() < 2) return false;
        int map[10001]{0};
        for(int card: deck) {
            map[card]++;
        }

        for(int i = 1; i < 10001; ++i) {
            if(map[i] != map[i-1] && gcd(map[i], map[i-1]) == 1)
                return false;
        }
        return true;
    }
};
```