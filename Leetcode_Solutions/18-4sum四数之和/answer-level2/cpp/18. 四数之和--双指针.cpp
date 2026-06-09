### 解题思路
执行用时 :60 ms 在所有 C++ 提交中击败了43.56%的用户
内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rt;
        if(nums.size() < 4) return rt;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0]*4 > target || nums[n-1]*4 < target) return rt;
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int g = n - 1;
                while(k < g){
                    if(nums[i]+nums[j]+nums[k]+nums[g] == target){
                        rt.push_back({nums[i], nums[j], nums[k], nums[g]});
                        g--;
                        while(nums[g] == nums[g+1] && k < g) g--;
                        k++;
                        while(nums[k] == nums[k-1] && k < g) k++;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[g] < target){
                        k++;
                    }
                    else{
                        g--;
                    }
                }
            }
        }
        return rt;
    }
};
```