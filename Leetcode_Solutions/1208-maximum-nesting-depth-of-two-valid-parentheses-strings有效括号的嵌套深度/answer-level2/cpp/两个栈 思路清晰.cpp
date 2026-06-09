### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> s1;
        stack<int> s2;
        vector<int> output;
        for(int i = 0;i < seq.size();i++)
        {
            if(seq[i] == '(')
            {
                if(s1.size() == s2.size())
                {
                    s1.push(1);
                    output.push_back(0);
                }
                else
                {
                    s2.push(1);
                    output.push_back(1);
                }
            }
            if(seq[i] == ')')
            {
                if(s1.size() == s2.size())
                {
                    s2.pop();
                    output.push_back(1);
                }
                else
                {
                    s1.pop();
                    output.push_back(0);
                }
            }
        }
        return output;
    }
};
```