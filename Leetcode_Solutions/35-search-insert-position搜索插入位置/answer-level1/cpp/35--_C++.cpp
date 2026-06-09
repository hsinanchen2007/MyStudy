### 解题思路
二分法

### 代码

```cpp
class Solution{
public:
    int searchInsert(vector<int>& nums, int target){
        int n=nums.size();
        if(n==0||nums[n-1]<target) return n;
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return left;
    }
};
```