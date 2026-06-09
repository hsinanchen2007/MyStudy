### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(),0);
        stack<int> stackTmp;
        stackTmp.push(INT32_MAX);
        for (int i = 0; i < T.size(); ++i) {
            while (stackTmp.top() != INT32_MAX && T.at(stackTmp.top())<T.at(i))
            {
                int index = stackTmp.top();
                stackTmp.pop();
                result.at(index) = i-index;
            }
            stackTmp.push(i);
        }
        return result;
    }
};
```