### 解题思路
一个括号配对的过程，将配对好的括号分别划分到0,1两个字符串

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        if(seq.empty())
            return res;
        stack<char> s;
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                res.push_back(s.size()%2);
                s.push(seq[i]);
            }
            else
            {
                s.pop();
                res.push_back(s.size()%2);
            }
        }
        return res;
    }
};
```