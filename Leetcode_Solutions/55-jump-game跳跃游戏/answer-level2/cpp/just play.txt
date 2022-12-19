其实很简单！

想象你是那个在格子上行走的小人，格子里面的数字代表“能量”，你需要“能量”才能继续行走。

每次走到一个格子的时候，你检查现在格子里面的“能量”和你自己拥有的“能量”哪个更大，取更大的“能量”！ 如果你有更多的能量，你就可以走的更远啦！~

```
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size() == 0)
            return true;

        int cur = nums[0], i = 1;
        for(; cur != 0 && i < nums.size(); i++)
        {
            cur--;
            if(cur < nums[i])
                cur = nums[i];
        }
        return i == nums.size();
    }
};
```
