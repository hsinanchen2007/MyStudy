### 解题思路
此处撰写解题思路
开个辅助数组a[],记录出现重复的牌。（0重复出现不算）若重复出现，则直接返回false
一次遍历，找出零的个数、最大值、最小值。
通过        int chazhi=big-small-(num.size()-zero)+1;
计算出差值，之后将差值与zero（即零的个数进行比较）。
### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int x,zero=0,big=0,small=20;
        int a[15]={0};
        for(int i=0;i<nums.size();i++)
        {
            if(a[nums[i]]==1&&nums[i]!=0)
            {
                return false;
            }
            a[nums[i]]=1;
            if(nums[i]==0)
                zero++;
             if(nums[i]>=big)
            {
                big=nums[i];
            }
              if(nums[i]<=small&&nums[i]!=0)
            {
                small=nums[i];
            }
        }
        int chazhi=big-small-(nums.size()-zero)+1;
          if(zero>=chazhi)
        {
           return true;
        }
        else
        {
            return false;
        }

    }
};
```