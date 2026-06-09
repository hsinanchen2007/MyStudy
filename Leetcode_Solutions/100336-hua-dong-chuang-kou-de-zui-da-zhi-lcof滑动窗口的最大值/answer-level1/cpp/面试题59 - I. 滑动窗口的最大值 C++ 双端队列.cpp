### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxOfWindow;   // 用来存放结果，长度为len-k+1，初始化为-1
        if(nums.empty()) return maxOfWindow;

        deque<int> index;   // 用来保存滑动窗口的最大值的队列，其中队首元素保存滑动窗口的最大值
        int len = nums.size();

        for(int i = 0; i < k; ++i){
            while(!index.empty() && nums[i] > nums[index.back()]){
                // 如果队列不为空，并且新加入的值比队列尾部的值要大，说明队列 尾部的值不可能成为最大值了，所以将队列尾部的值出队
                index.pop_back(); // 队尾出队
            }
            // 此时队首是当前滑动窗口的最大值,将当前索引值压入队列
            index.push_back(i);
        }
        
        for(int i = k; i < len; ++i){
            // 前一时刻将最大值加到最终结果
            maxOfWindow.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] > nums[index.back()]){
                // 如果队列不为空，并且新加入的值比队列尾部的值要大，说明队列 尾部的值不可能成为最大值了，所以将队列尾部的值出队
                index.pop_back();   // 队尾出队
            }
            if(!index.empty() && index.front() < (i - k + 1)){
                // 当前队列保存的最大值已经不再滑动窗口范围内，队列队首元素出队
                index.pop_front();
            }
            index.push_back(i);

        }
        // 此时队首是当前滑动窗口的最大值
        maxOfWindow.push_back(nums[index.front()]);
        return maxOfWindow;
    }
};
```