### 解题思路
要注意的是1 1，2 2这种，应该单独处理，否则mp每轮循环会多计数一次。

### 代码

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
           unordered_map<int, int> mp;
           int ans = 0;
           for(int i = 0 ; i < dominoes.size() ; ++i)
           {
               int a = dominoes[i][0] * 10 + dominoes[i][1];
               int b = dominoes[i][1] * 10 + dominoes[i][0];
               if(mp[a] > 0)
                    ans += mp[a];
                else if(mp[b] > 0)
                    ans += mp[b];
                mp[a] += 1;
                if(dominoes[i][0] != dominoes[i][1])
                    mp[b] += 1;
           }
        return ans;
    }
};
```