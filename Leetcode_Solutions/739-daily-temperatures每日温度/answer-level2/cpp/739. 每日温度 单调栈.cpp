### 解题思路
此处撰写解题思路

### 代码

```cpp
//单调栈来做
//一个足够大的数将解决前面的很多数
#include <stack>
#include <utility>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> resVec(T.size(), 0);
        stack<pair<int,int>> oneOrderStack;
        for(int i = 0; i < T.size(); ++i)
        {
            while(!oneOrderStack.empty() && oneOrderStack.top().second < T[i])
            {
                resVec[oneOrderStack.top().first] = i-oneOrderStack.top().first;
                oneOrderStack.pop();
            }
            oneOrderStack.push(pair<int,int>(i, T[i]));
        }
        return resVec;
    }
};
```