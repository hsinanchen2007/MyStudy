### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result=nums[0];
        int count=1;
        for(int i=1 ; i < nums.size() ; i++)
        {
            if(count==0)
            {
                count=1;
                result=nums[i];
            }
            else if(result==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return result;
    }
};
//因为超过一半，所以不同抵消之后，残余的哪一个一定是唯一数字（已知给定数组存在多数元素）
```