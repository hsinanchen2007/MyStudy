### 解题思路
单调队列，滑动窗口（其实每次维护的单调队列就是一个窗口，每次窗口向前滑动一个单位，主要的操作在push上）

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())return {};
        vector<int> ans;               
        deque<int> q;
        //用单调队列维护一个窗口
        for(int i = 0;i < nums.size();++i){
            //首次填满窗口
            if(i < k){
                //每次往窗口中push操作
                while(q.empty() || nums[i] > q.back()){
                    if(q.empty())break;
                    q.pop_back();
                }
                q.push_back(nums[i]);
                if(i == k-1)
                    ans.push_back(q.front());
            }else{
                //每次往窗口中push操作
                if(!q.empty() && nums[i-k] == q.front())q.pop_front();  
                while(q.empty() || nums[i] > q.back()){
                    if(q.empty())break;
                    q.pop_back();
                }
                q.push_back(nums[i]);
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};
```