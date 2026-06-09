```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i ++) {
            int index = i % n;
            while (!s.empty() && nums[s.top()] < nums[index]) {
                ans[s.top()] = nums[index];
                s.pop();
            }
            if (i < n) s.push(i);
        }
        return ans;
    }
};