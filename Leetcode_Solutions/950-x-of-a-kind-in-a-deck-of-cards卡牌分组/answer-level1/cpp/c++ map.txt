
### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if(n < 2) return false;
        unordered_map<int,int> mp;
        for(auto num:deck)
        {
            mp[num]++;
        }
        unordered_map<int,int>::iterator it = mp.begin();
        int cnt = (it++)->second;
        if(cnt == 1) return false;
        int g = cnt;  //最大公约数
        for(;it != mp.end();it++)
        {
            g = gcd(g,it->second); //求次数的最大公约数
        }
        return g >=2 ? true:false;
    }
};
```