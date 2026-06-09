```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        sort(nums.begin(),nums.end());
        while(i < len){
            if(i == len -1)
                break;
            if(nums[i] == nums[i+1]) {
                i = i+2;
                continue;   
            }
            if(nums[i] != nums[i+1])
               break;
        }
        return nums[i];
    }
};
```
看了异或感觉数电白学了。。