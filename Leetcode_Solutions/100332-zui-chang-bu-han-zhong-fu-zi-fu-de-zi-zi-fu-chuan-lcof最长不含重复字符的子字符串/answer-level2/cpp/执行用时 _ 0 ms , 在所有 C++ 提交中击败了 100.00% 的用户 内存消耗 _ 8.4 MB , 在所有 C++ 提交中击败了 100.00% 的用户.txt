### 解题思路
滑动窗口 + 哈希表

### 代码

```cpp
class Solution {
public:
    int dict[256];
    int lengthOfLongestSubstring(string s) {
        bzero(&dict,sizeof(dict));
        int ans = 0;
        for(int i=0,j=0;j<s.size();j++){
            if(dict[s[j]]==0)ans = max(ans,j-i+1);
            else{
                for(;i<dict[s[j]];i++)dict[s[i]] = 0;
            }
            dict[s[j]] = j+1;
        }
        return ans;
    }
};
```