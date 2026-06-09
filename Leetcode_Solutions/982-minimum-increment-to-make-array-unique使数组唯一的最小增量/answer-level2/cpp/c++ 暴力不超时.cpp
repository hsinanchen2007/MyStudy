### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int ans = 0;
        int cnt[50000] = {0};

        for (int i : A)
            ++cnt[i];

        for (int i = 0; i < 50000; ++i)
        {
            if (cnt[i] > 1)
            {
                cnt[i+1] += cnt[i]-1;
                ans += cnt[i]-1;
            }
        }
        return ans;
    }
};
```