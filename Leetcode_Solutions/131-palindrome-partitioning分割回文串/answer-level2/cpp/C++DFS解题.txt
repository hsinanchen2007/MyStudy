### 解题思路
这题没啥好说的，就是用回溯。
每次回溯记录当前开始分割的位置t，即从t开始走一步，或者多步。
然后逐渐累加步数，先验证从t走i步之后的字符串是不是回文。如果是回文，则保存这个子串，同时跳到下一个分割的位置。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tmpans;
    void dfs(string &s,int t)
    {
        if(t==s.size())
        {
            ans.push_back(tmpans);
            return;
        }
        for(int i=1;i<=s.size();i++)
        {
            if((t+i)>s.size())
                return;
            bool isOK=true;
            for(int j=0;j<i/2;j++)
            {
                if(s[j+t]!=s[t+i-1-j])
                {
                    isOK=false;
                    break;
                }
            }
            if(isOK)
            {
                tmpans.push_back(s.substr(t,i));
                dfs(s,t+i);
                tmpans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()<=1)
        {
            tmpans.push_back(s);
            ans.push_back(tmpans);
            return ans;
        }
        dfs(s,0);
        return ans;
    }
};
```