### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num  = nums[0];
        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i] != num)
            {
                count--;
                if(count < 0)
                {
                    count = 0;
                    num = nums[i];
                }
            }
            else
                count++;
        }
        return num;
    }
};
 
```