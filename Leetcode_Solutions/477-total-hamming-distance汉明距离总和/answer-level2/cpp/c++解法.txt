### 解题思路
先统计每个数二进制在每一位1的个数。汉明距离为 cnt[i] * (n-cnt[i])

### 代码

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for(auto num : nums){
            int i=0;
            while(num){
                if(num & 1)
                    cnt[i]++;
                num = num>>1;
                i++;
            }
        }
        int res = 0;
        int n = nums.size();
        for(auto c:cnt){
            res += c*(n-c);
        }
        return res;
    }
};
```