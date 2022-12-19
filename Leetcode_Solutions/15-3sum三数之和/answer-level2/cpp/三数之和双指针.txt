将nums排序，然后for循环遍历当作第一个元素，start指向i+1，end指向组后一个元素；
这样当nums[i]>0时，说明之后元素都大于0，就没有相加的必要的了，直接退出循环。如果和上一个元素一样，则直接跳过本轮循环。
在start和end中，如果三数之和小于0，则说明第二个元素不够大，要往后加（start++）,如果三数之和>0，说明end大了，要往前指(end--)
三数之和等于0的时候要start++并且end--以保证start变大的时候end变小来维持三数之和。
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)break;
            if(i>0&&nums[i]==nums[i-1])continue;
            int start=i+1;
            int end=nums.size()-1;
            if(start>=end)break;
            while(start<end){
                if(nums[i]+nums[start]+nums[end]==0){
                    res.push_back({nums[i],nums[start],nums[end]});
                    int temp1=nums[start];
                    int temp2=nums[end];
                    while(start<end&&nums[start]==temp1)
                        start++;
                    while(start<end&&nums[end]==temp2)
                        end--;
                }else if(nums[i]+nums[start]+nums[end]<0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return res;
    }
};
```
