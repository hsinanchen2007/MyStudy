### 解题思路
双向队列

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if ( k > n || n == 0) {
            return res;
        }
        deque<int> m_iDeque;
        for( int i = 0; i < k; ++i) {
            while(!m_iDeque.empty() && nums[m_iDeque.back()] < nums[i]) {
                m_iDeque.pop_back();
            } 
            m_iDeque.push_back(i);
        }
        res.push_back(nums[m_iDeque.front()]);
        for( int i = k; i < n; ++i) {
            if (!m_iDeque.empty() && i - m_iDeque.front() >= k ) {
                m_iDeque.pop_front();
            }
            while(!m_iDeque.empty() && nums[m_iDeque.back()] < nums[i]) {
                m_iDeque.pop_back();
            }
            m_iDeque.push_back(i);
            res.push_back(nums[m_iDeque.front()]);
        }
        return res;
    }
};
```