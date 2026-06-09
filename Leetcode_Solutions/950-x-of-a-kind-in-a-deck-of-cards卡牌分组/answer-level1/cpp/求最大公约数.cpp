和官方思路一样，求最大公约数。
```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        for(int x:deck){
            ++m[x];
        }
        int res=m[deck[0]];
        for(auto it=m.begin();it!=m.end();++it){
            if(it->second%res==0) continue;
            else res=gcd(res,it->second);
        }
        if(res>=2) return true;
        else return false;
    }
};
```
