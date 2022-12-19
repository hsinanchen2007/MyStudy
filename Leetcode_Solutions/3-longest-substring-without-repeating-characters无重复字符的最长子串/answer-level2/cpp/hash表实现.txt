### 解题思路
cnt维护动态hash范围

### 代码

```cpp
class Solution {
public:
    bool hash[256]={false};
    int lengthOfLongestSubstring(string s) {
        int cnt=0,maxn=0;
        for(int i=0;i<s.size();i++)
        {
            if(!hash[s[i]])
            {
                cnt++;
                hash[s[i]]=true;
                if(cnt>maxn) maxn=cnt;
            }
            else
            {
                while(s[i-cnt]!=s[i])
                {
                    hash[s[i-cnt]]=false;
                    cnt--;
                }
            }
        }
        return maxn;
    }
};
```