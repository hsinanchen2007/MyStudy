
### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.empty()) return true;
        if(astr.size()==1) return true;
        sort(astr.begin(),astr.end());
        for(int i=0;i<astr.size()-1;i++)
            if(astr[i]==astr[i+1]) return false;
        return true;
    }
};
```