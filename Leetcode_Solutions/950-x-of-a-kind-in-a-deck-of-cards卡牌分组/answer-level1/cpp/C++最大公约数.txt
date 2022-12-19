### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n=deck.size();
        if(n<2) return false;

        map<int,int> record;
        for(int i:deck)
        {
            record[i]++;
        }

        int gcd_x=record[deck[0]];
        for(auto m:record)
        {
            gcd_x=gcd(gcd_x,m.second);
            if(gcd_x==1) return false;
        }

        return true;
    }
};
```