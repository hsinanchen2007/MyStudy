执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗 :8.7 MB, 在所有 C++ 提交中击败了80.32%的用户

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        
        if(s.length() == 0)
            return 0;
        
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] != ' ')
                res++;
            else
            {
                if(res)
                    break;
            }
        }
        return res;
    }
};
```
