### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res=0;
        binary_search(nums,target,0,nums.size()-1,res);
        return res;
    }
    void binary_search(vector<int>& nums,int target,int left,int right,int &res){
        if(left>right) return;
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            ++res;
            binary_search(nums,target,left,mid-1,res);
            binary_search(nums,target,mid+1,right,res);
        }
        else if(nums[mid]<target){
            if(mid==right||target<nums[mid+1])
                return;
            binary_search(nums,target,mid+1,right,res);
        }
        else{
            if(mid==left||target>nums[mid-1]) return;
            binary_search(nums,target,left,mid-1,res);
        }
    }
};
```