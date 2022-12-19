

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left!=right){
            int mid=(right-left)/2+left;
            if(nums[mid]<nums[mid+1])
                if(nums[mid]<nums[nums.size()-1])
                    right=mid;
                else
                    left=mid+1;
            else 
                return nums[mid+1];                   
        }
        return nums[left];
    }
};
```