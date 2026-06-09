### 解题思路
括号序列合法等价于所有前缀和>=0，且总和等于0
如")()())"
则为-1 1 -1 1 -1 -1
start 当前枚举的这一段开头
cnt 前缀和
( = 1   ) = -1;
1.cnt < 0 => start =  i + 1, cnt = 0 //只要 < 0 说明某个) 永远也找不到( 与之对应，故可以直接到i + 1;
2.cnt > 0 => 继续做
3.cnt == 0 => [start, i]为合法序列

### 代码

```cpp
class Solution {
public:
    int work(string s)
    {
        int res = 0;
        for(int i = 0, start = 0, cnt = 0; i < s.size(); i++)
        {
            if(s[i] == '(') cnt++;
            else
            {
                cnt--;
                if(cnt < 0) start = i + 1, cnt = 0;
                else if(cnt == 0) res = max(res, i - start + 1);
            }
        }
        return res;
    }
    

    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(),s.end());
        for(auto &c:s)c ^= 1;
        return max(res,work(s));

    }
};
```