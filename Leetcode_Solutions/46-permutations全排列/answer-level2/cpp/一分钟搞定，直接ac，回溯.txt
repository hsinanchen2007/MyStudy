一分钟搞定，直接ac
```
    void traceback(vector<int>& nums, vector<vector<int>> &arr, int m){
        if(m == nums.size()){
            arr.push_back(nums);
            return ;
        }
        for(int i = m; i < nums.size(); ++i){
            swap(nums[m], nums[i]);            
            traceback(nums, arr, m + 1);
            swap(nums[i], nums[m]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        traceback(nums, arr, 0);
        return arr;
    }
```
