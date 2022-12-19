### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int cnt[80000] = { 0 };
        for (int x: A) cnt[x]++;

        int ans = 0, taken = 0;

        for (int x = 0; x < 80000; ++x) {
            if (cnt[x] >= 2) {
                taken += cnt[x] - 1;
                ans -= x * (cnt[x] - 1);
            }
            else if (taken > 0 && cnt[x] == 0) {
                taken--;
                ans += x;
            }
        }

        return ans;
    }
};
```