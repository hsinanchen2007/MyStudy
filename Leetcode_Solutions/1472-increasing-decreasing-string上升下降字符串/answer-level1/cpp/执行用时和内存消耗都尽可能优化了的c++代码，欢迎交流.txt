![1583997352(1).png](https://pic.leetcode-cn.com/011da652f09a95359e4a94bd389fc66873a09ec9e610a71456652dc7f65041e9-1583997352\(1\).png)


用vector代替map，因为都是小写字母，所以长度为26，用来存放每个字母的数量
用一个int来表示当前的状态，是该升序排列还是降序排列，1表示升序，-1表示降序

```
class Solution {
public:
    string sortString(string s) {
        string res = "";
        int way = 1;
        vector<int> ans(26,0);
        for(int n = 0; n < s.size(); n++)
        {
            ans[s[n]-'a']++;
        }
        while(res.size() <s.size())
        {
            if(way == 1)
            {
                for(int n = 0; n < 26; n++)
                {
                    if(ans[n]>0)
                    {
                        res += n+'a';
                        ans[n]--;
                    }
                }
                way = -1;
            }
            else
            {
                for(int n = 25; n >= 0; n--)
                {
                    if(ans[n]>0)
                    {
                        res += n+'a';
                        ans[n]--;
                    }
                }
                way = 1;
            }
        }
        return res;
    }

};
```
