### 解题思路
本题实质是求每个元素右边出现的第一个大于自身的元素位置，利用单调栈的思想。维护一个单调递减栈（自下而上递增），出栈时，栈顶元素右边第一个大于自身的元素为即将入栈的元素。

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size(), i = 0;
        vector<int> ans(len, 0);  //初始化vector数组
        stack<int> stacks;  //栈内维护的是元素的位置
        while(i < len)
        {
            if(stacks.size() && T[i] > T[stacks.top()])  //当栈不为空且满足当前元素大于栈顶元素时，栈顶元素出栈，更新栈顶元素的结果
            {
                ans[stacks.top()] = i - stacks.top();
                stacks.pop();
            }
            else
            {
                stacks.push(i);
                i ++;
            }
        }
        return ans;
    }
};
```