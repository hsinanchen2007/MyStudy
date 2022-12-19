判断最多改变一个元素的情况下，是否能变成一个非递减序列。
即找到一个元素 （大于其后面的那个元素）
此时有两种情况
1、改变该元素才能成为非递减序列
2、改变该元素后面那个元素才能成为非递减序列
由这两个元素的外围元素大小比较决定
若nums[i-2] > nums[i]
令nums[i] = nums[i-1];
否则：nums[i-1] = nums[i];
这样对于后面的判断就不会有影响了
```
class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int count = 0;
        //int tag = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                if(i-2 >= 0 && nums[i-2] > nums[i])
                    nums[i] = nums[i-1];
                else
                    nums[i-1] = nums[i];
                count++;
            }
        }
        return count <= 1;
    }
};
```
