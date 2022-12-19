### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index;
        int max1=0;
        int pre=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max1){
                pre=max1;
                max1=nums[i];
                index=i;
                continue;
            }
            if(nums[i]>pre){
                pre=nums[i];
            }
        }
        if(max1>=pre*2){
            return index;
        }
        return -1;
    }
};
```