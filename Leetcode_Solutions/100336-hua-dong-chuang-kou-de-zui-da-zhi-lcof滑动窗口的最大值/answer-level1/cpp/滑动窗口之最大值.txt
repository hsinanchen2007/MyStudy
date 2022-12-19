# 1. 理解
求滑动窗口最大值，以之前最大值队列的经验来说，应该第一时间想到单调双端队列。但是要主要窗口左右边界的变化，对应对双端队列的维护。
# 2. 思路
使用一个单调双端队列来记录当前滑动窗口的最大值：
1. **数据进入窗口**，和队尾元素比较，弹出所有比当前数据更小的队尾元素，然后当前元素队尾入队
2. **数据划出窗口**，和队首元素比较，如果划出数据和队首元素相等，则队首元素出队
# 3. 代码
```c++ []
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> wd;
        for(int i=0; i<nums.size(); i++){
            if(i-k >= 0 && nums[i-k] == wd.front()){
                wd.pop_front();
            }
            while(wd.size() && wd.back() < nums[i]){wd.pop_back();};
            wd.push_back(nums[i]);
            if(i >= k-1) {
                answer.push_back(wd.front());
            }
        }
        return answer;
    }
};
```
# 4. 总结
滑动窗口的最大值可以使用单调双端队列。
注意一下两个状态变化，对应的对双端队列的操作；
1. 数据划入窗口：队尾比较，小数出队，大数入队
2. 数据划出窗口：队首比较，相等则大数出队