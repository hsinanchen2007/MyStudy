### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size() || k <= 0) return -1;
        priority_queue<int> que;
        for (int i=0; i<nums.size(); i++) {
            que.push(nums[i]);
            if (que.size() > nums.size()-k+1) que.pop();
        }
        return que.top();
    }
};
```