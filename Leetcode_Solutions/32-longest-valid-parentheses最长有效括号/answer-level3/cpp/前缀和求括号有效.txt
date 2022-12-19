### 解题思路
括号序列合法< = > 所有前缀和>=0，且总和等于0。（左括号看成1，右括号看成-1，用cnt来记录）
由于前缀和有可能一直大于0，所以正反两个反向都需要枚举一遍。这里用一个函数即可。

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(),s.end());
        for(char &c:s)
        {
            if(c == '(') c = ')';
            else c = '(';
        }
        // for(char &c:s) c^=1;
        return max(res,work(s));
    }

    int work(string s)
    {
        int start = 0,cnt = 0;//cnt表示前缀和，start表示当前枚举这一段的开头。
        int res = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(') cnt++;
            else{
                cnt--;
                if(cnt<0) start = i + 1,cnt = 0;
                else if(!cnt) res = max(res,i - start + 1);
            }
        }
        return res;
    }
};
```