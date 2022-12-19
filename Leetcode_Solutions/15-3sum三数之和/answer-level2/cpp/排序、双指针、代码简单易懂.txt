### 解题思路
此处撰写解题思路
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> s={0,0,0};
        vector<vector<int>> res;

        for(int i=1;i<nums.size();i++){
            int tmp = nums[i];
            int j;
            for(j=i-1;j>=0;j--){
                if(tmp < nums[j]){
                    nums[j+1] = nums[j];
                }else{
                    nums[j+1] = tmp;
                    break;
                }
            }
            if(j == -1) nums[0] = tmp;
        }

       
        for(int i =0;i<nums.size()&&nums[i]<=0;){
            for(int j=i+1,k=nums.size()-1;j<k;){
                if(nums[i]+nums[j]+nums[k]>0)
                    while(--k<nums.size()&&j<k&&(nums[k+1]==nums[k]));
                else if(nums[i]+nums[j]+nums[k]<0){
                    while(++j<nums.size()&&j<k&&(nums[j-1]==nums[j]));
                }else {
                    s[0] = nums[i];
                    s[1] = nums[j];
                    s[2] = nums[k];
                    res.push_back(s);
                    while(++j<nums.size()&&j<k&&(nums[j-1]==nums[j]));
                    while(--k<nums.size()&&j<k&&(nums[k+1]==nums[k]));
                }
            }
            while(++i<nums.size()&&(nums[i-1]==nums[i]));
        }


        return res;  
    }
};
```