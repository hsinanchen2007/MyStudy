
### 代码

```cpp
class Solution {
    vector<vector<int>>res;
public:
    void swap(vector<int>&nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void perm(vector<int>&nums, int depth, int n){
        if(depth==n){
            res.push_back(nums);
        }
        else{
            for(int i = depth;i<n;i++){
                swap(nums,depth,i);
                perm(nums,depth+1,n);
                swap(nums,depth,i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0,nums.size());
        sort(res.begin(),res.end());
        return res;
    }
};
```