### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size(),mid;
        while(low<high){
            mid=(low+high)/2;
            if(target<nums[mid]) 
                high-=1;
            else if(target>nums[mid])
                low+=1;
            else
                return mid;
        }
        return -1;
    }
};
```