### 解题思路
等差数列求和，以此减去数组里的数，剩下的就是结果

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=nums.size()*(nums.size()+1)/2;
        for(int i=0;i<nums.size();i++){
            total-=nums[i];
        }
        return total;
    }
};
```
