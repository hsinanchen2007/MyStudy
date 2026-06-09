### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sizes=s.length();
        int sizet=t.length();
        int i=0;
        int j=0;

        while(j!=sizet)
        {
            if(t[j]==s[i])
            {
                i++;
                if(i==sizes)
                {
                    return true;
                }
            }
            j++;
        }

        return sizes?false:true;

    }
};
```