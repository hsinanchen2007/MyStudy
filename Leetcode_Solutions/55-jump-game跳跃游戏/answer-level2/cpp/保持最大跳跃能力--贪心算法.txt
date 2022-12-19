**思路**    设置一个最大跳跃能力变量max，往后对数组进行遍历，每往后一个位置则原先的max减一，与当前位置跳跃能力即数值进行比较取最大值，则此时为当前位置的最大跳跃能力。当max为0时，则
            不能跳到最后一个位置，返回false；否则运行到倒数第二个位置，退出后返回true。
**代码**
class Solution {
public:
    bool canJump(vector<int>& nums) {                   //每一步都保持最大跳跃能力
        int n=nums.size();
        if(n<=0)
            return false;
        if(n==1)
            return true;
        int max=nums[0];
        if(max==0)
            return false;
        for(int i=1;i<n-1;++i)
        {
            max=(max-1)<nums[i]?nums[i]:(max-1);
            if(max==0)
                return false;
        }
        return true;
    }
};

执行用时 :12 ms, 在所有 cpp 提交中击败了82.01%的用户
内存消耗 :9.8 MB, 在所有 cpp 提交中击败了88.25%的用户