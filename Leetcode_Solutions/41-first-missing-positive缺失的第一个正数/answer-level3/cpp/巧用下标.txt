### 解题思路
此处撰写解题思路
---关键信息---
1. 目标范围：1 \le target \le nums.size()
2. 借助输入数据空间

代码思想：
1. \forall value in nums[*], if 1 \le value \le size, then replace the value to this position it should be, whose index match the value.
2. when the value not in the target range, then there is not a position ,whose index match the value.
3. after the processing to the list with step 2 and 3, finally ,we can get that all the value are in the position whose index match the value,so 
4. the first value is our final answer.
### 代码

```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int & a, int & b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int index=0;
        while(index<nums.size())
        {
            int target = index+1;
            if(nums[index] != target)
            {
                if( 1<=nums[index] && nums[index] <= nums.size() && nums[nums[index]-1] != nums[index])
                {
                    swap(nums[index], nums[nums[index]-1]);
                    continue;
                }
            }

            index++;
        }
        for(int xIndex=0; xIndex<nums.size(); ++xIndex)
        {
            if(nums[xIndex]!=xIndex+1)
            {
                return xIndex+1;
            }
        }
        return nums.size()+1;
    }
};
```