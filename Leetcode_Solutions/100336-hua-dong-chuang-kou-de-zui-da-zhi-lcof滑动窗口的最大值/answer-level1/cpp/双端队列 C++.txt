```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<2) return nums;
        vector<int> res;
        deque<int> q; //存储当前滑动窗口中较大值的下标
        for(int i = 0; i<nums.size(); i++){
            while(q.size() && nums[q.back()]<=nums[i]) //删除队列中比当前值小的值
                q.pop_back();
            if(q.size() && i-q.front()>=k) //队列头滑出窗口则删除
                q.pop_front();
            q.push_back(i); //当前值入队
            if(i>=(k-1))res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```
