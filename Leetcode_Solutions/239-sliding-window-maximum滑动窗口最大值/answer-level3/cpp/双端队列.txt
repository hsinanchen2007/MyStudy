1.判断队首元素是否还在窗口内，不在就移除队列
2.将队列中比当前数小的全部移除，当前数入队列
3.如果窗口中有k个值了，则开始保存最大值（即队首元素）

```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> q;
        
        for (int i = 0; i < n; i++)
        {
            if (q.size() && i - q.front() >= k) q.pop_front();
            while (q.size() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
	return res;
    }
};
```
