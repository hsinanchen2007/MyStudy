### 解题思路
每次判断while循环中的当前元素是否比栈顶元素大，如果大则计算出下标的差值，并弹出栈顶元素；
否则将当前元素的下标压入栈顶，开始下一个元素的判断
【注意】：栈中存放的是下标，不是数组元素的真实值
### 代码

```cpp
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        vector<int>ans(T.size(),0);
        stack<int>res;
        int i=0;
        while(i<T.size())
        {
            while (!res.empty() && T[i]>T[res.top()])
            {
                ans[res.top()]=i-res.top();
                res.pop();
            }
            res.push(i);
            i++;
        }
        return ans;
    }
};
```