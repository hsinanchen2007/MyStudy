### 解题思路
依旧是按位异或数字相同的结果为0
对于数组元素其出现的可能性只有0，1，···，n;
则将所有的数组，异或，并且将0，1，2···，n异或，
则结果就是在数组中没有出现的那个数字。

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for(int i =0;i<nums.size();i++)
        {
            ret = ret^i^nums[i];
        }
        return ret^nums.size();

    }
};
```