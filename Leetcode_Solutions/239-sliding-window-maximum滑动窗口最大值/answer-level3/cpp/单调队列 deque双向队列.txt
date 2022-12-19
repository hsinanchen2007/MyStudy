### 解题思路
将队列按照递减的顺序存放。

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;
        for(int i = 0; i < nums.size(); i++)
        {
            if(q.size() && i - k + 1 > q.front()) q.pop_front();//如果说q存在，从i往前数k个数，如果大于队首，说明队首滑出窗口，弹出队首
            while(q.size() && nums[q.back()] <= nums[i])q.pop_back();//如果说q存在，同时队尾小于当前元素，弹出队尾
            q.push_back(i);//加入当前位置
            if(i >= k - 1)res.push_back(nums[q.front()]);//需要滑动k个位置才能加入数组
        }
        return res;
    }
};
```