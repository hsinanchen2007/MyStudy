### 解题思路
即找下一个更大元素， 求的是下一个更大元素与当前元素的下标之差（天数）

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        vector<int> res(T.size());

        stack<int> stack;

        for (int i = 0; i < T.size(); ++i)
        {
            while (!stack.empty() && T.at(i) > T.at(stack.top()))
            {
                int index = stack.top();
                stack.pop();
                res.at(index) = i - index;
            }
            stack.push(i);
        }

        return res;
    }
};
```