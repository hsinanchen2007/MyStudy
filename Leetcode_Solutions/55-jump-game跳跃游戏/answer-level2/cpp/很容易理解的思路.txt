### 解题思路
思路就是找出当前能走的最大的步数，在遍历的同时看当前值是否可达到末尾，如果可以，直接返回
时间复杂度：o(n)
解题的时候并没有想着说用贪心或者动态规划，但写出来之后感觉是贪心

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
        {
            return false;
        }
        else if(nums.size()==1)
        {
            return true;
        }
        
        int size = nums.size();
        int maxCnt = nums[0];       //最多能走的步数
        for(int i=0; i<size&&maxCnt>=0; i++)
        {
            // 找最大步数
            if(nums[i] > maxCnt)
            {
                maxCnt = nums[i];
            }

            // 看当前值是否可直达末尾
            if(nums[i] >= size-1-i)
            {
                return true;
            }

            // 每走一步减一步
            maxCnt--;
        }

        return false;
    }
};
```