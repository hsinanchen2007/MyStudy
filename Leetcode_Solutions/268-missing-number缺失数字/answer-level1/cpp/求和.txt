### 解题思路
求出数组的和，然后用0到n的和减去之，就是缺少的数字了。

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); int sum=0;
        for(int i=0; i<n;i++)
            sum+=nums[i];
        return (1+n)*n/2-sum;
    }
};
```