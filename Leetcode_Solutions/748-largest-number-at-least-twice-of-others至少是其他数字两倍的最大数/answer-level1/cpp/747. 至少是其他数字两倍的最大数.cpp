### 解题思路
找到最大的两个数即可

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int id0=-1;
        int id1=-1;
        if(nums[0]<nums[1])
        {
            id0=1;
            id1=0;
        }
        else
        {
            id0=0;
            id1=1;
        }

        for(int i=2;i<n;++i)
        {
            if(nums[i]>nums[id0])
            {
                id1=id0;
                id0=i;
            }
            else if(nums[i]>nums[id1])
            {
                id1=i;
            }
        }

        if(nums[id0]>=nums[id1]*2)return id0;
        else return -1;
    }
};
```