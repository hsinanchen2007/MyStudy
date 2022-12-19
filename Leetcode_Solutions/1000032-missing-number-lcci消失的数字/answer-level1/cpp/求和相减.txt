### 解题思路
1. 运用求和公式对0,1,...,n求和
2. 遍历nums，所得之和依次减去nums[i]，返回结果

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(int i=0;i<nums.size();i++)
            sum-=nums[i];
        return sum;
    }
};
```