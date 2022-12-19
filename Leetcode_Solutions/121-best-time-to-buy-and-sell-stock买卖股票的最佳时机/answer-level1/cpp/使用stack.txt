### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_ans = 0;
        if(prices.size()<=1) return max_ans; 
        stack<int> s;
        s.push(prices[0]);
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<s.top())
            {
                s.pop();
                s.push(prices[i]);
            }
            else
            {
                int x = prices[i]-s.top();
                max_ans= max(max_ans,x);
            }
        }
        return max_ans;
    }
};
```