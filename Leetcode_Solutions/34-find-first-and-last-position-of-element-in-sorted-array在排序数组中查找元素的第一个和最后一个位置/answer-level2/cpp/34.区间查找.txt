### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> result;
        result.push_back(Left_bound(nums,target));
        result.push_back(right_bound(nums,target));
        return result;
    }
private:
    int Left_bound(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        while(begin<=end)
        {
            int mid=(begin+end)/2;
            if(target==nums[mid])
            {
                if(mid==0||target>nums[mid-1])
                    return mid;
                end=mid-1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else if(target>nums[mid])
            {

                begin=mid+1;
            }
        }
        return -1;
    }
    int right_bound(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        while(begin<=end)
        {
            int mid=(begin+end)/2;
            if(target==nums[mid])
            {
                if(mid==nums.size()-1||target<nums[mid+1])
                    return mid;
                begin=mid+1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else if(target>nums[mid])
            {
                begin=mid+1;
            }
        }
        return -1;
    }

};
```