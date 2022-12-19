### 解题思路
此处撰写解题思路
去重得下心思。。。。太可怕了
### 代码

```cpp 
//create by ChiCex 2020/2/12 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> group;
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right=nums.size() - 1;
            while(left<right){
                int temp = nums[i]+nums[left]+nums[right];
                if(temp==0){
                    vector<int> v = {nums[i],
                    nums[left],
                    nums[right]};
                    result.push_back(v);
                    left+=1;right-=1;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                else if(temp > 0){
                    right-=1;
                }else if(temp <0){
                    left+=1;
                }
            }
        }
        return result;
    }
};
```