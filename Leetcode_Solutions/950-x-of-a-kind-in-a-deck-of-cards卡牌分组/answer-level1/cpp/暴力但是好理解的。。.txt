### 解题思路
先特判1的情况，其他情况判断是否由最大公约数即可

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int d[10000] ={0},cnt = 0,x=0;
        for(int i = 0;i<deck.size();i++)
        {
            d[deck[i]]++;
        }
        for(int i = 0;i<10000;i++)
        {
            if(d[i] != 0) cnt++;
        }
        if(cnt == 1)
        {
            for(int i = 0;i<10000;i++)
            {
                if(d[i] != 0)
                {
                    if(d[i]<2) return false;
                    else return true;
                }
            }
        }
        for(int i = 0;i<10000;i++)
        {
            if(x && d[i])
            {
                if(gcd(x,d[i]) < 2) return false;
                else x = gcd(x,d[i]);
            }
            if(!x && d[i])
            {
                x = d[i];
            }
        }
        return true;
    }
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
};
```