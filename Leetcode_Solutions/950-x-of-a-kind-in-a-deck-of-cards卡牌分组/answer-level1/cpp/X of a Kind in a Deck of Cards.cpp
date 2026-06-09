### 解题思路
X of a Kind in a Deck of Cards

### 代码

```cpp
class Solution {
    int cnt[1000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for(int i=0;i<deck.size();i++)
        {
            cnt[deck[i]]++;
        }
        int X=cnt[0];
        for(int i=0;i<1000;i++)
        {
        if(cnt[i]==1) return false;
        X=gcd(X,cnt[i]);
        if(X==1) return false;
        }
        return true;
    }
    int gcd(int x,int y)
    {
    if(y==0) return x;
    return gcd(y,x%y);
    }
};
```