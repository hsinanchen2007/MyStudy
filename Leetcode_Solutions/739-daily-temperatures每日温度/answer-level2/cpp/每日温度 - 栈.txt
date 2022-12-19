### 解题思路
栈顶元素和当前元素比较，若当前元素比栈顶元素大，则出栈。
比较直到栈被清空或栈顶元素比当前元素大，将当前元素压入栈中。

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> idx ;
        if(T.empty()) return idx ;

        idx.resize(T.size(), 0) ;

        stack<pair<int, int>> stk ;

        for(int i=0 ; i<T.size(); i++)
        {
            while(!stk.empty() && T[i]>stk.top().second)
            {
                idx[stk.top().first] = i - stk.top().first ;
                stk.pop() ;
            }
            stk.push({i , T[i]}) ;
        }

        return idx ;
    }
};
```