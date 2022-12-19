### 解题思路
此处撰写解题思路
去重复
### 代码

```cpp
class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i=l;
        int j=r;
        int mid = nums[l];
        while(i < j){
            while(i<j && nums[j] > mid) j--;
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i] < mid) i++;
            if(i<j) nums[j--] = nums[i];
        }
        nums[i] = mid;
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // quickSort(nums, 0, nums.size()-1);
        vector<vector<int>> v;
        if(nums.size() < 3) return v;
        sort(nums.begin(), nums.end());
        int i=0, j=0, k=0;
        set<vector<int>> ans;
        for(k=0; k<nums.size()-2; ++k){
            //不加这行会超时
            if(k>0 && nums[k] == nums[k-1]) continue;
            int s = -nums[k];
            i=k+1;
            j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]==s){
                    ans.insert(vector<int>{nums[k], nums[i], nums[j]});
                    i++;
                }
                else if(nums[i] + nums[j] < s){
                    i++;
                }else{
                    j--;
                }
            }
        }
        
        for(auto it: ans){
            v.push_back(it);
        }
        return v;
    }
};
```