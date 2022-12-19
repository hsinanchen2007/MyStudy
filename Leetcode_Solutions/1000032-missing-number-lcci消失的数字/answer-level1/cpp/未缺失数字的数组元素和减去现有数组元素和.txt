
### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int num:nums) sum-=num;
        return sum;
    }
};
```