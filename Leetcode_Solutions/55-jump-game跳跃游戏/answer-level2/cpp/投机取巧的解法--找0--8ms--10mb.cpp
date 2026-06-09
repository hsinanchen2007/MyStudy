### 解题思路
在我们跳跃的道路上，只有0能阻挡我们的前进，既然如此只需要找到每一个0并判断我们是否能越过这个0就可以了(当这个0在w末尾的时候不需要越过)。投机取巧的方法，随便看看开心就好，正规算法请见官方题解。
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;//[]
        if (nums[0] == 0)
        {
            if (nums.size() == 1) return true;//[0]
            else  return false;//[0,......]我们在第一步就被阻止了前进
        }
        bool flag1 = true;
        for (int i = 1; i < nums.size()-1; ++i)
        {
            if (nums[i] == 0)
            {
                bool flag2 = false;
                int j = i-1;
                while (j >= 0 && !flag2)//判断这个0是不是一个可以过去的坎
                {
                    flag2 = flag2 || nums[j] > i - j - 1;
                    --j;
                }
                flag1 = flag1 & flag2;//记录经过这个坎以后我们还能否到达终点
            }
        }
        return flag1;
    }
};
```