

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right){//left=right结束，
            int mid=(left+right)/2;
            if(nums[mid]<nums[right]){
                right=mid;//因为mid小，所以可能是最小值，所以取mid
            }
            else left=mid+1;//因为mid大，所以不可能是最小值，所以取mid+1
        }
        return nums[left];
    }
};
```