```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k<=0) return vector<int>();
        vector<int> v(nums.size()-k+1);
        deque<int> q;
        for(int i=0;i<k;++i)
        {
            while(!q.empty() && nums[q.front()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        for(int i=k;i<nums.size();++i)
        {
            v[i-k]=nums[q.front()];
            /////队列最前的元素小则删
            while(!q.empty() && nums[q.front()]<=nums[i])
                q.pop_back();
            ////超出范围删大
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            ///// 比当前 队列为空或者队列首元素大的添加
            q.push_back(i);
        }
        v[nums.size()-k]=nums[q.front()];
        return v;
    }
};
```
