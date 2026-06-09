### 解题思路
因为两个相同的数异或的结果为0，所以将这个数组的所有数全部进行一次异或运算，则结果即为只出现了一次的数，因为出现两次的数，；两两相消之后，所有的位全部为0

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0;i<nums.size();i++)
        {
            ret = ret^nums[i];
            
        }
        return ret;
    }
};
```