### 解题

### 代码

```cpp
class Solution {
public:
    int gys(int x, int y)
    {
        if (y > x)
        {
            int t = y;
            y = x;
            x = t;
        }
        while (x != y)
        {
            int t = x - y;
            x = t> y ? t: y;
            y = t < y ? t : y;
        }
        return x;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<2)
        return false;
        else if(deck.size()==2)
        {
            if(deck[0]!=deck[1])
                return false;
            else
                return true;
        }
        map<int,int> count;
        for(int i=0;i<deck.size();i++)
        {
            count[deck[i]]++;
        }
        map<int,int>::iterator it=count.begin();
        if(count.size()==1)
        {
            for(int i=2;i<it->second/2;i++)
            {
                if(it->second%i==0)
                return true;
            }
        }
        else
        {
            it=count.begin();
            int tem=gys(it->second,(++it)->second);
            if(tem==1)
                return false;
            for(it=count.begin();it!=count.end();it++)
            {
                tem=gys(tem,it->second);
                if(tem==1)
                    return false;
            }
            
        }
        return true;
    }
};
```