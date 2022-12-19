### 解题思路
此处撰写解题思路
根据数组特性和存储的整数，将数组下标和数组内的数一一对应存储，如果碰到重复的数字，那么必然能够从数组中检测到
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        
        for(int i=0 ; i < nums.size() ; i++)
        {
            //判断数组下标是否与该位置上的整数相同，如果不同，则将该整数和对应的索引交换
            //如nums[0] = 9, 那么就应该赋值nums[9] = 9
            if( nums[i] != i )
            {
                //交换前先判断当前索引是否已经有了相应的整数
                //如nums[9] = 9 已经有了，那么第二次判断必然就是重复数，将其输出
                if( nums[nums[i]] == nums[i] ) 
                    return nums[i];
                
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }

    
};
```