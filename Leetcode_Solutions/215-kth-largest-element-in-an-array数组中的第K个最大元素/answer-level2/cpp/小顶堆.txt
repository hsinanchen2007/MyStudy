### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k > n) return 0;
        priority_queue<int, vector<int>, greater<int>> stack;
        for(int i = 0; i < n; i++){
            stack.push(nums[i]);
            if(stack.size() > k) stack.pop();
        }
        int rt = stack.top();
        return rt;
    }
};
```