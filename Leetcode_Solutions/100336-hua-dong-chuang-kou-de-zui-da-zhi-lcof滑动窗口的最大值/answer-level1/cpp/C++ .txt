### 解题思路
双向队列

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0||k==1) return nums;
        deque<int> deq;
        vector<int> res;
        int maxnum = INT_MIN;
        for(auto a : nums)
        {
            deq.push_back(a);
            maxnum = max(maxnum,a);
            if(deq.size()==k)
            {
                res.push_back(maxnum);
                if(deq.front()==maxnum)
                {
                    deq.pop_front();
                    int temp = INT_MIN;
                    for(int i = 0;i<deq.size();i++)
                    {
                        int a = deq.front();
                        temp = max(temp,a);
                        deq.pop_front();
                        deq.push_back(a);
                    }
                    maxnum = temp; 
                }
                else 
                {
                    deq.pop_front();
                }
            }
        }
        return res;
    }
};
```