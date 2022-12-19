贪心上升的时候贪最大的，下降的时候贪最小的
状态机，三个状态互相转换
```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        const int begin=0;
        const int up=1;
        const int down=2;
        int state=begin;
        int max_length=1;//大于2的元素摇摆长度至少为1
        for(int i=1;i<nums.size();i++)
        {
            switch(state)
            {
                case begin:
                    if(nums[i]-nums[i-1]>0)
                    {
                        state=up;
                        max_length++;
                    }else if(nums[i]-nums[i-1]<0){
                        state=down;
                        max_length++;
                    }
                    break;
                case up:
                    if(nums[i]-nums[i-1]<0)//下一个状态为down时记录该位置长度加一,其他up过程不计入长度
                    {
                        state=down;
                        max_length++;
                    }
                    break;
                case down:
                    if(nums[i]-nums[i-1]>0)//下一个状态为up时记录该位置长度加一，其他down过程不计入长度
                    {
                        state=up;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};

```
