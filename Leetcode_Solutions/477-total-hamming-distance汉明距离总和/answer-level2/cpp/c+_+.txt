### 解题思路
所有数第一位为1的数量乘第一位为0的数量 + 所有数第二位同上

### 代码

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(32, 0);
        int n = nums.size();
        for(auto t : nums){
            int i = 0;
            while(t){
                cnt[i] += t & 1;
                t >>= 1;
                ++i;
            }
        }
        int ans = 0;
        for(auto t : cnt) ans += t * (n - t);
        return ans;
    }
};
```