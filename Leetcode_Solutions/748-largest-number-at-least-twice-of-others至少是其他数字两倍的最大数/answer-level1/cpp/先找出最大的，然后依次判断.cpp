### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=0;
        int index=-1;
      for(int i=0;i<nums.size();i++)
        {
            if(max<nums[i])
            {
                max=nums[i];
                index =i;
            }
            
        }
    for(int i=0;i<nums.size();i++)
        {
           
            if(max<nums[i]*2&&i!=index)
            {
                return -1;
            }
        }
        return index;
    }
};
```