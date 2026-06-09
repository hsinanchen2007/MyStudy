```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1){
            return 0;
        }
        int firstmax = 0;
        int secondmax = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[firstmax]&&nums[i]>nums[secondmax]){
                int temp = firstmax;
                firstmax = i;
                secondmax = temp;
            }
            else if(firstmax==secondmax||nums[i]>nums[secondmax]){
                secondmax = i;
            }
        }
        if(nums[firstmax]>=nums[secondmax]*2){
            return firstmax;
        }
        return -1;
    }
};
```
一次遍历找到最大和第二大的数字。
