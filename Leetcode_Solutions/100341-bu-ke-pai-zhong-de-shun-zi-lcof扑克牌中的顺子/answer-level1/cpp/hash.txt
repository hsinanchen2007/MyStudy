### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt0=0;
        int index[14];
        memset(index,0,sizeof(index));
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)continue;
            index[nums[i]]++;
            if(index[nums[i]]>1)return false;
        }

        int left=0,right=0;
        for(int i=1;i<=13;i++)
        {
            if(index[i]==1)
            {
                if(left==0)
                    left=i;
                else right=i;
            }
        }
        if(right-left<=4)return true;
        else return false;
    }
};
```