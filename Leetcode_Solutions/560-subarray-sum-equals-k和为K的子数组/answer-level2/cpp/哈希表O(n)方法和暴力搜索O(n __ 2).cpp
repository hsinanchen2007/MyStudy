### 解题思路

### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // auto sums = std::vector<int>(nums.size() + 1);
        // for (auto i = 0; i < nums.size(); i++) {
        //     sums[i + 1] = sums[i] + nums[i]; 
        // }
        // int cnt = 0;
        // for (auto i = 0; i < sums.size(); i++) {
        //     for (auto j = i + 1; j < sums.size(); j++) {
        //         if (sums[j] - sums[i] == k) cnt++;
        //     }
        // }
        // return cnt;
        std::map<int, int> sum_freqs;
        int cur_sum = 0;
        sum_freqs[0] = 1;
        int cnt = 0;
        for (auto i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            auto diff = cur_sum - k;
            // std::cout << diff << '\n';
            if (sum_freqs.find(diff) != sum_freqs.end()) cnt += sum_freqs[diff]; 
            if (sum_freqs.find(cur_sum) != sum_freqs.end()) sum_freqs[cur_sum] += 1;
            else sum_freqs[cur_sum] = 1;
        }
        return cnt;
    }
};
```