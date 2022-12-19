### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                int t=-nums[i];
                if(nums[t-1]>0){
                    nums[t-1]=-nums[t-1];
                }
            }
            else{
                if(nums[nums[i]-1]>0){
                    nums[nums[i]-1]=-nums[nums[i]-1];
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
```