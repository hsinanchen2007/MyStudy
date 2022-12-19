### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> a;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<s.length()+1;i++)
        {
            a.push_back(0);
        }
        a[0]=1;
        for(int i=0;i<s.length();i++)
        {
            if(a[i]==1)
            {
            for(int j=0;j<wordDict.size();j++)
            {
                if(equal(wordDict[j],s,i)==1)
                {
                    a[i+wordDict[j].length()]=1;
                }
            }
        }
        }
        return a[s.length()];
    }
    bool equal(string word,string s,int curr)
    {
        if(word.length()+curr>s.length()) return false;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]!=s[curr+i]) return false;
        }
        return true;
    }
};
```