
- 暴力
```
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>>temp;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 for(int k=j+1;k<nums.size();k++){
//                     for(int m=k+1;m<nums.size();m++){
//                         if(nums[i]+nums[j]+nums[k]+nums[m]==target){
//                             temp.insert({nums[i],nums[j],nums[k],nums[m]});
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>>res(temp.begin(),temp.end());
//         return res;
//     }
// };
```

- 双指针
别说四数之和了，k数之和都可以用这玩意，时间复杂度O(n^(k-1)),就是一个模板
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return {};
        sort(nums.begin(),nums.end());
        set<vector<int>>temp;
        for(int first=0;first<=nums.size()-4;first++){
            for(int second=first+1;second<=nums.size()-3;second++){
                int third=second+1;
                int fourth=nums.size()-1;
                while(third<fourth){
                    if(nums[first]+nums[second]+nums[third]+nums[fourth]==target){
                        temp.insert({nums[first],nums[second],nums[third],nums[fourth]});
                        third++;
                        fourth--;
                    }else if(nums[first]+nums[second]+nums[third]+nums[fourth]<target){
                        third++;
                    }else{
                        fourth--;
                    }
                }
            }
        }
        vector<vector<int>>res(temp.begin(),temp.end());
        return res;
    }
};
```