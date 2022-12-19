```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> val;
        if(nums.size() >= k && k >= 1){
        for(int i = 0;i < k; ++i){
            while(!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
            q.push_back(i);
        }
        for(int i = k; i < nums.size(); ++i){
            val.push_back(nums[q.front()]);
            while(!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            if(!q.empty() && q.front() <= i - k)
                q.pop_front();
                q.push_back(i);
        }
        val.push_back(nums[q.front()]);
    }
    return val;
    }
};
```
单调递减队列维护区间最大值

具体步骤分解:
1·窗口最多可有k个元素,那么第一个for循环即处理前k个元素,并且将Maxvalue的下标存入队列 (注意队列非空 && 入队元素值 >= 队首元素值)
2·第二个for循环从k开始 直到size结束,我们将第一个for循环里处理的Maxvalue下标存入queue.
3·循环处理至结束
此处有一点点需注意: 1·最大值从窗口滑出的下标判断,需是从队首出队(若是从队尾出,会将已入队的新最大值出队,从而导致错误)

