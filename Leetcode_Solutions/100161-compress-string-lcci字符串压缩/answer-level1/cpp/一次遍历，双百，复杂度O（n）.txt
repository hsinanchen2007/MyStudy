### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) 
    {
        string res;
        if(S.size() == 0)
            return res;
        
        char now = S[0];
        int n = 0;
        int i = 0;
        
        for(i = 0; i < S.size(); i++)
        {
            if(S[i] == now)
            {
                n ++;
            }
            else
            {
                res += S[i - 1];
                res += to_string(n);

                n = 1;
                now = S[i];
            }
        }
        res += S[i - 1];
        res += to_string(n);


        return S.size() > res.size() ? res : S;
    }
};
```