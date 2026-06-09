### 解题思路
使用栈来解决

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S) 
    {
        string ans_str;
        ans_str.push_back(S[0]);
        for(int i = 1; i < S.size(); ++i)
        {
            bool flag = 1;
            while(ans_str.size()!=0 && ans_str[ans_str.size() - 1] == S[i])
            {
                flag = 0;
                ans_str.pop_back();
            }
            if(flag) ans_str.push_back(S[i]);
        }
        return ans_str; 
    }
};
```