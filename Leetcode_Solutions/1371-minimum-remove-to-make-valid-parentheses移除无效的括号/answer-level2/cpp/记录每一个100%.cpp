### 解题思路
记录"("时顺便用栈记录下位置，到时候如果有")"剩余，就可以把记录位置的栈拿出来一起清除
执行用时:52 ms,击败了32.45%
内存消耗:12.8 MB,击败了100.00%
### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<char> sign = {};//记录符号
        stack<int> location = {};//记录位置，到时候是倒着删，不会影响下一个待删除的(
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                sign.push(s[i]);
                location.push(i);
            }
                
            if (s[i] == ')')
            {
                if (!sign.empty())//若非空，证明里面有东西，所以不用动
                {
                     sign.pop();
                     location.pop();
                }
                else //里面没东西，需要删除
                {
                    s.erase(s.begin()+i);
                    i--;
                }
            }
        }
        while (!location.empty())
        {
            s.erase(s.begin()+location.top());
            location.pop();
        }
        return s;
    }
};
```