### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b){
        int c=b;
        while(a%b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        return c;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        for(int i=0;i<deck.size();i++)
            m[deck[i]]++;
        map<int,int>::iterator it;
        int fac=(*m.begin()).second;
        for(it=m.begin();it!=m.end();it++)
        {
            fac=gcd(fac,it->second);
            if(fac<=1) return false;
        }
        return true;
    }
};
```