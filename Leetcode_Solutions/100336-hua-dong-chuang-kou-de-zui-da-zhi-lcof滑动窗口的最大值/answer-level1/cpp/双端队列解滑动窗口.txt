### 解题思路
用一个双端队列，存储滑动窗口中最大值的id

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            if(!q.empty()&&i-q.front()>=k){
                q.pop_front();
            }
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
```