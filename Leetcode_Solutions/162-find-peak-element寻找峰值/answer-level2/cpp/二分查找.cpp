对于中间节点k而言，如果nums[k]>nums[k+1]，则区间[0,k]必然存在峰值。
反之(不存在nums[k]==nums[k+1]，则必然nums[k]<nums[k+1])，在区间[k,end)必然存在峰值，准确讲，在区间[k+1,end)必然存在峰值。
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        for(int k, j=nums.size()-1; i<j;){
            k=(i+j)/2;
            if(nums[k]>nums[k+1]) j=k;
            else i=k+1;
        }
        return i;
    }
};
```
