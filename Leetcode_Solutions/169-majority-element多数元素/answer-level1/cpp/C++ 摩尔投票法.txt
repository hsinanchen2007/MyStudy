### 解题思路
C++ 摩尔投票法

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*摩尔投票法*/
        int candidate = nums[0];
        int count = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(candidate!= nums[i]){
                count --;
            if(count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            }
            else 
            count ++;
        }
        return candidate;
    }
};
```