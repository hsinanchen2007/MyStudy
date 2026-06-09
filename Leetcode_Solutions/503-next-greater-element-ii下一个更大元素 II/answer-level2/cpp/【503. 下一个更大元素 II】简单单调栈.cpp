### 思路
本题数可以循环，所以通过在一个临时数组中保存两次原数组来处理循环。当数组扩大一倍后，对于超过原数组下标的数，采用模运算来处理可以得到在原数组中的下标。

相同类型题目[739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/solution/739-mei-ri-wen-du-liang-chong-fang-fa-di-jian-zhan/)

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {        
        vector<int> res(nums.size(), -1), tmp(nums);
        stack<int> st;
        for (auto n : nums) {
            tmp.push_back(n);
        }
        for (int i = 0; i < tmp.size(); ++i) {
            while (!st.empty() && tmp[i] > tmp[st.top()]) {
                res[st.top()%nums.size()] = tmp[i];//使用模运算来处理超过原来下标
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
```