### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        sort(deck.begin(), deck.end());
        vector<int> lens;
        int min_len = 1e9;
        int cnt = 1;
        for (int i = 1 ; i < deck.size(); i ++ ) {
            if (deck[i] == deck[i - 1]) {
                cnt ++;
            } else {
                lens.push_back(cnt);
                cnt = 1;
            }
        }
        lens.push_back(cnt);
        if (lens.size() == 1 && lens[0] >= 2) return true;

        min_len = gcd(lens[0],lens[1]);
        if (min_len < 2) return false;
        
        for (auto &len : lens){
            min_len = gcd(len, min_len);
        }

        return min_len >= 2;
    }
};
```