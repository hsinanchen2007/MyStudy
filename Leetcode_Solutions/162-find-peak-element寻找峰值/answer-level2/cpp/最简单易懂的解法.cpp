//-1 n是负∞
//相邻元素不等
结论：求数组最大值的下标 

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[j]<nums[i])
                j=i;            
        }
        return j;
    }
};
```
