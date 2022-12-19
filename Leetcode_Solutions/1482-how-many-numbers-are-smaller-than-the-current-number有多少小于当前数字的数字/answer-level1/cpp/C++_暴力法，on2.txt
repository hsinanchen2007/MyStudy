### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size(),0);

        
        for(int i=0;i<nums.size();i++)
        {
            int temp=0;
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j&&nums[j]<nums[i])
                {
                    ++temp;
                }
            }
            res[i]=temp;
        }
        return res;
    }
};
```