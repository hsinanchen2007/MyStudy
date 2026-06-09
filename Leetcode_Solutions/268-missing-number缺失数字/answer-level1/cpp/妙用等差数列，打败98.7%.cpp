### 解题思路
等差数列是高考数学的重要一题型，今可谓大用。
用数列和sum减去nums中的数据，剩下的数就是缺失的数据

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*(nums.size()+1))/2;
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;

    }
};
```