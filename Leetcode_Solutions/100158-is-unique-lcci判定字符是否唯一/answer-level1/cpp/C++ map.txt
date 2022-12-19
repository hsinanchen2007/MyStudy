
```
class Solution {
public:
    bool isUnique(string astr) {
     //map
        map<char,int>m;
        for (auto i :astr)
        {
            if(m[i]==1){return false;}
            m[i]=1;
        }
        return true;
    }
};

```
   