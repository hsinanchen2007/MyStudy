### 解题思路
队列存放下标
当前数大于队尾则队尾出队，小于等于则入队尾
检查队头是否滑出去了

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        if(nums.empty())    return res;

        deque<int>q;
        for(int i = 0;i < k;i++){             //k个一组
            while(!q.empty() && nums[i] > nums[q.back()]) 
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);

        for(int i = k;i < nums.size();i++){
            if(!q.empty()&&q.front() < i-k+1) q.pop_front();
            while(!q.empty()&&nums[i] > nums[q.back()]) 
                q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```