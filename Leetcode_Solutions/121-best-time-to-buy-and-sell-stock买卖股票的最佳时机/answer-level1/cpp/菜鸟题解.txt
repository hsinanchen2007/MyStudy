### 解题思路
这个够简单的了，初学c++都能看懂。。。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> p;
        for(int i = 0;i<prices.size();i++)
        {
            for(int j = i+1;j<prices.size();j++)

            if(prices[i]<prices[j])
            p.push_back(prices[j]-prices[i]);
        }
        sort(p.rbegin(),p.rend());
        if(p.size() == 0)
        return 0;
        else
        return p[0];
    }
};
```