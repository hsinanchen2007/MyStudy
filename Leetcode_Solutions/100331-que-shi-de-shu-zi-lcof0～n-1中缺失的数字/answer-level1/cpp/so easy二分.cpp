so easy 二分，直接递归，如果这个nums是一个有序的那么返回-1,根据第一个元素是否是0，判断是最后一个元素+1，还是0.
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // 如果这个数在中间[0,1,3]
        int res = recursion(nums,0,n-1);
        if(res != -1) return res; 
        // 排除[0,1,2]与[1,2,3]有序结果
        return nums[0] == 0 ? nums[n-1]+1 : 0;   
    }
    int recursion(vector<int>& nums,int left,int right) {
        if(left>right) return -1;
        
        int mid = left + (right-left) / 2;
        if(mid+1 < nums.size() && nums[mid] + 2 == nums[mid+1])
            return nums[mid]+1;
        int res1 = recursion(nums,left,mid-1);
        int res2 = recursion(nums,mid+1,right);
        if(res1 == -1) return res2;
        return res1;
    }
};
```