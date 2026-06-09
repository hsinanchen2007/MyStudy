### 解题思路
遍历，将从这个数开始的每个数之后的和都加起来，如果==k，res++；

### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pool;
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<pool.size();j++){
                pool[j]+=nums[i];
                if(pool[j]==k) res++;
            }
            pool.push_back(nums[i]);
            if(nums[i]==k) res++;
        }
        return res;
    }
};
```