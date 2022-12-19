```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=-1;
        int blue=nums.size();
        int cur=0;
        while(cur<blue){
            if(nums[cur]==0){
                swap(nums[cur],nums[red+1]);
                ++red;
                ++cur;
            }else if(nums[cur]==2){
                swap(nums[cur],nums[blue-1]);
                --blue;
            }else{
                ++cur;
            }
        }
    }
};
```
