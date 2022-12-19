### 解题思路
#### 1.首先对拿到手的牌从小到大排序
#### 2.统计大小王的个数
#### 3.对于不是大小王的牌，看是否和下一位的牌连续（(1)如果和下一张牌相等 return false;(2)如果和下一张牌连续则continue;如果不相等且不连续，统计中间空缺的牌的个数）
#### 4.最后将空缺的牌（lose）的个数和大小王（king）的个数比较：king>=lose return ture;否则 return false;
### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int king = 0;  
        int lose = 0;  
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == 0)  king++;
            else 
            {
                 
                if(nums[i+1]==nums[i]) return false;
                if(nums[i+1]-nums[i] == 1) continue;
                else lose+=nums[i+1]-nums[i]-1;
            }

        }
        if(king>=lose) return true;
        else return false;
    }
};
```