### 解题思路
    思想：假装数组长度变成了两倍，然后配合单调栈进行 逆序（从后往前）计算
    日常膜大佬，打卡学习 ~ ~ ~
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 2 * n - 1;i >= 0;i--){
            while(!s.empty() && s.top() <= nums[i % n])
                s.pop();
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};
```