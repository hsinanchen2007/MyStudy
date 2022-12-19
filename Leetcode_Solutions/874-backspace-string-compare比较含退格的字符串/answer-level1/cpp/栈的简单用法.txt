![批注 2019-12-17 190024.png](https://pic.leetcode-cn.com/9d6f9c2123789869ded546253710050319a917b1d35c17d961ed92f8baff241d-%E6%89%B9%E6%B3%A8%202019-12-17%20190024.png)

### 解题思路
1.通过空间换时间，使用两个栈，分别存储两个字符串
2.遍历比较两个栈，如有不同，则返回false，否则，返回true。

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        int si = 0;
        stack<char> t;
        int ti = 0;
        while(S[si])
        {
            if(S[si] == '#')
            {
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else
            {
                s.push(S[si]);
            }
            ++si;
        }
        while(T[ti])
        {
            if(T[ti] == '#')
            {
                if(!t.empty())
                    t.pop();
            }
            else
                t.push(T[ti]);
            ++ti;
        }
        while(!s.empty() && !t.empty())
        {
            if(s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        if(!s.empty() || !t.empty())
            return false;
        return true;
    }
};
```