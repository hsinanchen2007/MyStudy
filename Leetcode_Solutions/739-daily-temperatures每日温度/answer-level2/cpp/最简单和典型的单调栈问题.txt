### 解题思路
最简单和典型的单调栈问题

### 代码

```cpp
/*从左向右遍历，单调递减单调栈，从左向右是因为它是求“几天后”，
单调递减是因为要求是后面比当前温度高的结果*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> st;
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {//从左向右
        /*比较依据的是温度，将要入栈日期的温度如果比栈顶日期的温度大，说明找到了一个超过栈顶日期温度的日期，
        栈顶日期出栈并将日期差值存入结果*/
            while (!st.empty() && T[i] > T[st.top()]) {
                ans[st.top()] = i - st.top();//在出栈的过程中，每个栈顶元素都找到了答案
                st.pop();
            }

            st.push(i);//因为求的是索引差(日期差)，所以存索引
        }

        return ans;
    }
};
```