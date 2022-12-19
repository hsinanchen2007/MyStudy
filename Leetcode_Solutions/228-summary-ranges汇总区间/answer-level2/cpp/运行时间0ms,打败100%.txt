```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx = 0;
        vector<string> res;
        while(idx < (int)nums.size()){
            long long init_num = nums[idx];
            long long cur_num = nums[idx];
            while(idx+1 <(int)nums.size() && nums[idx+1] - cur_num == 1)
                cur_num = nums[++idx];
            if(init_num == cur_num)
                res.push_back(to_string(init_num));
            else
                res.push_back(to_string(init_num) + "->" + to_string(cur_num));

            idx++;
        }
        return res;
    }
};
```
