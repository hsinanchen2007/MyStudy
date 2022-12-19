### 解题思路
本题思路特别类似用map解决2sum的解决方法，利用map查询累计和是否存在sum[i],,满足sum[j]-sum[i] = k,来一次完成对满足要求的子数组的查找。sum[i]是从0开始到i的累计和。

### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> SUMS; //<sum till i , sum appearance time>
        SUMS[0] = 1;
        for (auto &m : nums) {
            sum += m;
            count += SUMS[sum - k];
            //sum[i] means sum till i
            //if exists sum[i] = sum[j] - k, satisfying subarray appears 
            ++SUMS[sum];//add one to the appearance time of this sum
        }
        return count;
    }
};
```