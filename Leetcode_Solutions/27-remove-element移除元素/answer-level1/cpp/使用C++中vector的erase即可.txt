```
int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == val){
            nums.erase(nums.begin() + i);
            --i; //由于删除了当前的重复元素，所以要恢复过来
        }
    }
    return nums.size();
}
```
