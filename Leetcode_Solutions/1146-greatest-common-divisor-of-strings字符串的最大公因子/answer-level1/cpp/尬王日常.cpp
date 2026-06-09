### 解题思路
此题有点尬，我用了最土味的方法来做。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()==0||str2.size()==0){return "";}
        if(str1[0]!=str2[0]){return "";}
        int ma = max(str1.size(),str2.size());
        int mi = min(str1.size(),str2.size());
        string restemp = "";string res = "";
        for(int i = 0;i<mi;i++)
        {
            if(str1[i]!=str2[i]){return res;}
            restemp+=str1[i];
            if(ma%restemp.size()!=0){continue;}
            if(mi%restemp.size()!=0){continue;}
            string temp1 = "";string temp2 = "";
            for(int j = 0;j<ma/restemp.size();j++)
            {
                temp1+=restemp;
            }
            for(int j = 0;j<mi/restemp.size();j++)
            {
                temp2+=restemp;
            }
            if(str1.size()==ma){if(str1==temp1&&str2==temp2){res = restemp;}}
            if(str2.size()==ma){if(str2==temp1&&str1==temp2){res = restemp;}}
        }
        return res;
    }
};
```