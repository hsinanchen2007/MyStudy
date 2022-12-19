### 解题思路
单调队列思想, 维护一个单调递减队列，队列头存储当前窗口最大值在数组的index, 遍历数组nums不断更新队列头，即可获取所有窗口的最大值
时间复杂度 O(n)
空间复杂度 O(n)
### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> res;
        int len = nums.size();
        vector<int> data;
        for (int i = 0; i < len; i++) {
            //判断当前滑动窗口是否已经滑过队列头index指向的元素，是则从队列中删除该元素的index
            if ((res.size()) && (i - k + 1 > res.front())) {
                res.pop_front();
            }
            //维护一个单调递减的队列，队列头存储的元素是当前滑动窗口最大值的在数组的下标
            while ((res.size()) && (nums[res.back()] <= nums[i])) {
                res.pop_back();
            }
            res.push_back(i);
            if (i >= k - 1) { 
                //当i>=k-1时，滑动窗口中的元素个数已经达到k, 可以开始获取最大值，队列头
                data.push_back(nums[res.front()]);
            }
        }
        return data;
    }
};
```