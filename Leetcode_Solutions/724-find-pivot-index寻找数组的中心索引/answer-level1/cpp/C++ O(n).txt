```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,now=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(sum-now-nums[i]==now) return i;
            now+=nums[i];
        }
        return -1;
    }
};
```
