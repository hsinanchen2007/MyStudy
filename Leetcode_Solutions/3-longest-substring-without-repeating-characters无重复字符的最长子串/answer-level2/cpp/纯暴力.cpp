### 解题思路
纯暴力。。。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        int ans = 0;
        vector<char> vv;
        for(int i = 0; i < s.size();i++)
        {
            bool flag = true;
            for(int j = 0; j < vv.size(); j++)
            {
                if(s[i] == vv[j])
                   {
                       flag = false;
                       i = i - vv.size() + 1;
                       break;
                       
                   }
            }
            if(flag)
            {
                vv.push_back(s[i]);
                if(vv.size() > ans)
                   ans = vv.size();
            }
              
            else
            {
                vv.clear();
                vv.push_back(s[i]);

            }
              
            

        }
        return ans;
        
        
    }
};
```