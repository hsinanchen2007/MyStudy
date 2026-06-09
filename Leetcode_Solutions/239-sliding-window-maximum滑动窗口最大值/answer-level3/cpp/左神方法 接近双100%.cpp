```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //        双端队列中只保存最大值
        deque<int> que;
        vector<int> res(nums.size() - k + 1, 0);
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
//            队列中的所有值都比当前值小的话 pop
            while(!que.empty() &&  nums[que.back()] <= nums[i]){
                que.pop_back();
            }
//            当前值push
            que.push_back(i);
            if(que.front() == i - k){
                que.pop_front();
            }
            if(i >= k - 1){
                res[index++] = nums[que.front()];
            }
        }
        return res;
    }
};
```
