### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int j = 0; j < nums.size()-1; j++)
        {
            if(nums[j] == nums[j+1] && nums[j] != 0)
            {
                return false;
            }
        }//判断是否有除了大小王的重复数字
        int mmax = nums[4];
        int mmin = 14;
        for(int i = 0; i < 5; i++)
        {
            if(nums[i] < mmin && nums[i] != 0)  mmin = nums[i];
        }
        int res;
        res = mmax - mmin + 1;
        return (res <= 5);
    }
};


 //(max-min+1) > 5 则无法构成 （对于无重复数字而言）
 //若数字重复则直接返回false
```