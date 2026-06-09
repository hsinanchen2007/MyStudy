### 解题思路
**桶排序，再累加作hash**

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 统计每个数字的个数
        int count[101]{0};
        for(int elem : nums){
            count[elem] += 1;
        }
        // 对统计的结果依次做累加
        int prev = count[0]; count[0] = 0;
        for(int i = 1;i<101;++i){
            int cur = count[i];
            count[i] = count[i-1] + prev;
            prev = cur;
        }
        vector<int> result(nums.size());
        for(int i = 0; i<nums.size(); ++i){
            result[i] = count[nums[i]];
        }
        return result;
    }
};
```