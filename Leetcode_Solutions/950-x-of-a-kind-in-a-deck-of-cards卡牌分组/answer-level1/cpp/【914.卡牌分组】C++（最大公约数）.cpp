### 解题思路
求所有整数出现次数的最大公约数，判断是否>=2

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for(int card: deck){
            cnt[card]++;
        }
        int _gcd = 0;
        for(auto it:cnt){
            if(it.second<2)
                return false;
            _gcd = gcd(_gcd, it.second);
            if(_gcd==1)
                return false;
        }
        return true;
    }
};
```