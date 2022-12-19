```
bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    vector<int> mins(nums.size());
    stack<int> stk;
    mins[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        mins[i] = nums[i] < mins[i-1] ? nums[i] : mins[i-1];
    }
    for (int i = (int)nums.size() - 1; i >= 0; i--) {
        if (nums[i] > mins[i]) {
            while (!stk.empty() && mins[i] >= stk.top()) {
                stk.pop();
            }
            if (!stk.empty() && stk.top() < nums[i]) {
                return true;
            }
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
    }
    return false;
}
```
