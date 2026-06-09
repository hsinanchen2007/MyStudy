记得写break，不然后面后相同的也会算进去。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        int r=0;
        bool b=true;
        for(int i=0;i<strs[0].size();i++)
        {
            b=true;
            for(int n=1;n<strs.size();n++)
            {
                if(strs[0][i]!=strs[n][i])
                {b=false;break;}
            }
            if(b==true)
            r++;
            else break;
        }
        string res=strs[0].substr(0,r);
        return res;
    }
};
```