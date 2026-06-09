### 解题思路
先放剩的多的，因为如果先放少的，那么少的放完以后，大的有可能超过3个，就不满足了。

### 代码

```cpp
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans = "";
        int len = A + B;
        while(ans.length() < len)
        {
            if(ans.length() >= 2)
            {
                if(ans[ans.length() - 1] == 'a' && ans[ans.length() - 2] == 'a')
                {
                    ans += "b";
                    B -= 1;
                    continue;
                }
                if(ans[ans.length() - 1] == 'b' && ans[ans.length() - 2] == 'b')
                {
                    ans += "a";
                    A -= 1;
                    continue;
                }
                if(A > B)
                {
                    A -= 1;
                    ans += "a";
                }
                else
                {
                    B -= 1;
                    ans += "b";
                }
            }
            else
            {
                if(A > B)
                {
                    A -= 1;
                    ans += "a";
                }
                else
                {
                    B -= 1;
                    ans += "b";
                }
            }
        }
        return ans;
    }
};
```