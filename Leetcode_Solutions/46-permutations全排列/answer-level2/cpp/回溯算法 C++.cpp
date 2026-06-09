
```

vector<vector<int>> res;

void backtrack(vector<int>& nums, vector<int> track){
    if (track.size() == nums.size()) {
        res.push_back(track);
        return ;
    }
    for (int i=0; i<nums.size(); i++) {
        if (find(track.begin(), track.end(), nums[i]) != track.end()) {
            continue;
        }
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track;
    backtrack(nums,track);
    return res;
}

```