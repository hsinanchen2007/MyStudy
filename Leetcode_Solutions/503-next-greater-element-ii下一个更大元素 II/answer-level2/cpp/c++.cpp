### 解题思路
单调栈，取余代替扩展数组

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);        
        stack<int> s;
        for(int i = 2*nums.size()-1;i >= 0;--i){
            while(!s.empty() && nums[i%nums.size()] >= s.top())s.pop();
            if(s.empty())ans[i%nums.size()] = -1;
            else ans[i%nums.size()] = s.top();
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};
```