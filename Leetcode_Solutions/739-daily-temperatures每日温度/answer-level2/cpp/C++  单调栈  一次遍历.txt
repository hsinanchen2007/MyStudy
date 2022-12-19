# 数据结构
* **单调栈定义**

    单调栈是按单调性维护栈内元素的栈。分为单调递增栈和单调递减栈。

* **单调栈适合的问题**

    1. 计算数组中每个数右边（或左边）第一个比它大（或小）的数，并计算二者之间的距离。
    2. 寻找数组中的某个子数组，使得子数组中的最小值乘以子数组的长度最大。
    3. 寻找数组中的某个子数组，使得子数组中最小值乘以子数组所有元素和最大。

# 伪代码
```cpp
/*
* 对应单调递减栈
*/
vector<int> array;
// 为了便于数组最后一个元素的处理
array.push_back(INT_MIN);
for (int i = 0; i <= len; ++i) {
    if (栈为空或入栈元素大于等于栈顶元素) 入栈;
    else {
        while (栈非空并且入栈元素小于等于栈顶元素) {
            出栈;
            更新结果;
        }
        将最后一次出栈的栈顶元素入栈; // 即当前元素可以拓展到的位置
        更新最后一次出栈的栈顶元素其对应的值;
    }
}
输出结果;
```
# 题目分析

翻译过来就是，寻找每个位置右边第一个比它大的元素，计算二者之间的距离。
典型的单调栈问题。

# 本题答案
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return vector<int>();
        vector<int> res(T.size(), 0);
        T.push_back(INT_MIN);
        
        stack<int> stk;
        for (int i = 0; i < T.size(); ++i) {
            if (stk.empty() || T[i] < T[stk.top()]) {
                stk.push(i);
            } else {
                // 这里不需要等于，因为题干要求必须大于当前温度
                while (!stk.empty() && T[i] > T[stk.top()]) {
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};
```