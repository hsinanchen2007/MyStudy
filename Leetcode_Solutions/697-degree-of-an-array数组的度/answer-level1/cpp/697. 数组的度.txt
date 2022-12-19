## 三个哈希表存储每个数的个数和起始索引
*搬运大佬的*
```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int num_cnt[50000]={0}, start[50000], end[50000];
        int max_idx = -1;
        for(int i=0; i < nums.size(); i++){
            int num = nums[i];
            num_cnt[num]++;
            if(num_cnt[num] == 1) start[num] = i;
            end[num] = i;
            if(max_idx == -1) max_idx = i;
            else{
                int max_num = nums[max_idx];
                if (num_cnt[max_num] < num_cnt[num] 
                    || num_cnt[max_num] == num_cnt[num] && end[max_num]-start[max_num] > end[num]-start[num]){
                    max_idx = i;
                }
            }
        }
        if (max_idx == -1) return 0;
        int max_num = nums[max_idx];
        return end[max_num] - start[max_num] + 1;
    }
};
```
## unordered_map和vector存储每个数的所有索引
```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size(), minlen=0, du=0;
        unordered_map<int, vector<int> > um;
        for(int i=0; i<len; i++){
            um[nums[i]].push_back(i);
            int size = um[nums[i]].size();
            if(size>du){
                du = size;
                minlen = um[nums[i]][size-1] - um[nums[i]][0] + 1;
            }
            if(size==du)
                minlen = min(minlen, um[nums[i]][size-1] - um[nums[i]][0] + 1);
        }
        return minlen;
    }
};
```