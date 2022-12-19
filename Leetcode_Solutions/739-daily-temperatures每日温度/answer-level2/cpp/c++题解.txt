创建一个递减栈
后入栈的元素总比先入栈的元素小。

![IMG_657地7.jpg](https://pic.leetcode-cn.com/677050b4dab35f7d41087c197b407583b911532847b0df82d13e9f44bd7a98a6-IMG_657%E5%9C%B07.jpg)

以上为过程图，从右到左操作。

若当前数据比栈top数据小， 则入栈；若当前数据比栈top大，先pop栈，直到当前数据比栈的top数据小，再入栈。



```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> ans (T.size(), 0);
        stack <int> res;
        for(int i = T.size()-1; i >= 0; --i)
        {
            while(!res.empty() && T[i] >= T[res.top()]) res.pop();
            if(res.empty())
                ans[i] = 0;
            else
                ans[i] = res.top() - i;
            res.push(i);
        }
        return ans;
    }
};
```