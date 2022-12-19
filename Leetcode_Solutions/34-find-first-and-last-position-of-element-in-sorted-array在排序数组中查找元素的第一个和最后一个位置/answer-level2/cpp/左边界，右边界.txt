### 解题思路
先检索左边界，再检索右边界
注意high的范围
注意空集的情况

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        if (nums.size()==0) return res;
        int high=nums.size()-1,low=0;
        while(low<high){
            int mid=(low+high)/2;
            nums[mid]<target?low=mid+1:high=mid;
        }
        if (nums[low]==target) res[0]=low;
        else if (nums[low]!=target) return res;
        high=nums.size();
        while(low<high){
            int mid=(low+high)/2;
            nums[mid]>target?high=mid:low=mid+1;
        }
        res[1]=low-1;
        return res;  
    }
};
```