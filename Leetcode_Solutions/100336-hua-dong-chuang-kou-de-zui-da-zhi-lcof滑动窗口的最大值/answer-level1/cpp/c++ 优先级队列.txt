### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        map<int, int> del;
        for(int i = 0; i < k-1; i++) pq.push(nums[i]);
        for(int i = k-1; i < nums.size(); i++){
            pq.push(nums[i]);
            ans.push_back(pq.top());
            int out = nums[i-(k-1)];
            del[out]++;
            while(del[pq.top()] > 0){
                del[pq.top()]--;
                pq.pop();
            }
        }
        return ans;
    }
};
```