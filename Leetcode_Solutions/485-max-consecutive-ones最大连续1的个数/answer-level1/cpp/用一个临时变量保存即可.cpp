### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen=0;
        int tem_max=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                tem_max++;
            }
            else
            {
                tem_max=0;
            }
            if(maxlen<tem_max)
            {
                maxlen=tem_max;
            }
        }
        return maxlen;
    }
};
```