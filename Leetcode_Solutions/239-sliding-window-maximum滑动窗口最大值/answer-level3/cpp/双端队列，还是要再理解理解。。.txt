### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0)return {};
        vector<int> res;
        deque<int> window;  //滑动窗口，用于存储下标
        //初始化大小为k的窗口
        for(int i = 0; i < k; ++i)
        {
            while(!window.empty() && nums[i] > nums[window.back()])
            {
                //窗口非空且当前数大于窗口最后一个下标对应的数
                window.pop_back();  //弹出队尾
            }
            window.push_back(i);  //window.front()对应的数是当前窗口最大数
        }
        //初始化的窗口的最大数
        res.push_back(nums[window.front()]);
        //滑动窗口
        for(int i = k; i < nums.size(); ++i)
        {
            if(!window.empty() && window.front() <= i-k)
            {
                //队头对应的下标不属于当前窗口，即window.front() <= i-k
                window.pop_front();  //弹出队头
            }
            while(!window.empty() && nums[i] > nums[window.back()])
            {
                //对当前窗口操作
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};
```