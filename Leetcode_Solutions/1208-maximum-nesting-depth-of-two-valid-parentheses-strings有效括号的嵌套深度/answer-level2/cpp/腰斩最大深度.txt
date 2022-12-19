### 解题思路
先跑一遍测最大深度，因为人家说了，它是合法括号串，所以肯定不会出现有左括号没右括号，或者还没左括号就有右括号的情况。那么就大胆地跑，出现一个左括号深度+1，出现一个右括号深度-1，记录最大左括号（如果不保证是合法括号串的话，有可能记录的左括号深度不合法，还需要注意有可能深度会减到0以下）。

将括号分成两组，其最大深度最多也就只能腰斩，跑第二遍，只要加入括号后深度小于等于最大深度的一半且大于等于0，就将当前括号加入res中。搞定。
用时4ms，内存消耗7.5MB，感觉是截至目前为止遇到的最简单的一道中等难度题。

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int m = 0,cur = 0;
        for(int i = 0; i < seq.size(); i++)
        {
            if(seq[i] == '(')
            {
                cur++;
                if(cur > m)
                    m = cur;
            }
            else
                cur--;
        }
        vector<int> res(seq.size());
        for(int i = 0; i < seq.size(); i++)
        {
            if(seq[i] == '(' && cur <= m / 2 - 1)
            {
                res[i] = 1;
                cur++;
            }
            else if(seq[i] == ')' && cur >= 1)
            {
                res[i] = 1;
                cur--;
            }
        }

        return res;
    }
};
```