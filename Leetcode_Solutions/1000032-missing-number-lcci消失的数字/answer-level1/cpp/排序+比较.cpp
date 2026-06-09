### 解题思路
先对原来数组排序，然后对应的下标与数组中的nums[i]比较，如果不相等，则返回这个值，否则返回下一个值。

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int tmp = 0;
        for(int i=0;i<nums.size();i++)
        {
            tmp = i;
            if(i != nums.at(i))
                return i;
        }
        return tmp+1;
    }
};
```