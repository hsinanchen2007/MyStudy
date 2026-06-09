### 解题思路
分两次吧，一次是考虑奇数的回文，第二次考虑偶数的回文

执行用时 :20 ms, 在所有 C++ 提交中击败了89.43%的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了92.47%的用户

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len<=1)
            return s;

        int maxOffset = 0, index = 0;
        int flag = 0;
        
        for (int i=0; i<len; i++)
        {
            int offset = 1;
            while (i-offset >= 0 && i+offset < len)
            {
                if (s[i-offset] == s[i+offset])
                {
                    offset++;
                }
                else
                {
                    break;
                }
            }
            offset--;
            if (offset > maxOffset)
            {
                maxOffset = offset;
                index = i;
                flag = 1;
            }
        }

        for (int i=0; i<len-1; i++)
        {
            if (s[i] == s[i+1])
            {
                int offset = 1;
                while (i-offset >= 0 && i+1+offset < len)
                {
                    if (s[i-offset] == s[i+1+offset])
                    {
                        offset++;
                    }
                    else
                    {
                        break;
                    }
                }
                offset--;
                if (offset >= maxOffset)
                {
                    maxOffset = offset;
                    index = i;
                    flag = 2;
                }
            }
        }

        if (flag == 2)
        {
            return s.substr(index-maxOffset, maxOffset*2+2);
        }
        else
        {
            return s.substr(index-maxOffset, maxOffset*2+1);
        }

    }
};
```