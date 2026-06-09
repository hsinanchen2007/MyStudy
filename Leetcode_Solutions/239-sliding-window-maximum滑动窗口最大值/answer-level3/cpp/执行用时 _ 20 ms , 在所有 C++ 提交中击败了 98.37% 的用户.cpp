### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
private:
    deque<int>q;
public:
    void clean_deque(int i, int k,vector<int>& nums)
    {
        if(!q.empty()&&q.front() == i-k)
        {
            q.pop_front();
        }
        while (!q.empty() && nums[i] > nums[q.back()])                                      q.pop_back();

    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int N = nums.size();
        if(N == 0 || k == 0)
        {
            return {};
        }
        if(k == 1)
        {
            return nums;
        }
        vector<int>res(N-k+1,0);
        int max_index = 0;
        for (int i = 0; i < k; i++) 
        {
            clean_deque(i, k,nums);
            q.push_back(i);
            if (nums[i] > nums[max_index]) max_index = i;
        }
        res[0] = nums[max_index];
        for (int i  = k; i < N; i++) 
        {
            clean_deque(i, k,nums);
            q.push_back(i);
            res[i - k + 1] = nums[q.front()];
        }
        return res;
    }
};




```