### 解题思路
// 维持一个单调递增的双向队列， 然后依次进行如下三步:
// (1) 当队首元素超出窗口时，将队首元素出队
// (2) 添加元素(弹出至队尾元素大于该值)
// (3) 将队头元素对应的位置即为最大值

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> m_deque;
        vector<int> res;
        
        for(int i = 0; i< nums.size(); i++){
            // 出队: 队首元素到当前元素超出窗口大小时
            if(!m_deque.empty() && (i-m_deque.front() > k-1)) m_deque.pop_front();
            
            // 入队: 一直弹出到大于该值
            // 注意这里是 <=
            while(!m_deque.empty() && (nums[m_deque.back()] <= nums[i])) m_deque.pop_back(); 
            m_deque.push_back(i);
            
            // 添加最大值
            if(i >= k-1) res.push_back(nums[m_deque.front()]);
        }
        
        return res;
    }
};
```