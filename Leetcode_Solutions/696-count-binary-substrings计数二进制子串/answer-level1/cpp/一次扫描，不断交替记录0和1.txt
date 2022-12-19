### 解题思路
来自评论区某大神的思路，感觉非常巧妙

### 代码

```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int last,cur,res;
        last=res=0;cur=1;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]==s[i-1])
            cur++;
            else
            {
                last=cur;
                cur=1;
            }
            if(last>=cur) res++;
        }
        return res;
    }
};
```