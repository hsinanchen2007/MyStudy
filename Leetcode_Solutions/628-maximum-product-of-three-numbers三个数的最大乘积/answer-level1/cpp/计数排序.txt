### 解题思路
将原有的sort排序，替换为计数排序，效率提高

### 代码

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 计数排序，提升效率
        int arr[2001] = {0};
        for (auto n : nums) {
            ++arr[n + 1000];
        }
        int val1 = 1;
        int i = 0, cnt = 2;
        for (int i = 0; i < 2000 && cnt > 0; ++i) {
            if (arr[i] == 0) continue;
            
            int times = min(arr[i], cnt);
            cnt -= times;
            val1 *= pow(i - 1000, times);
        }

        int last = INT_MAX, val2 = 1;
        cnt = 3;
        for (int i = 2000; i >= 0 && cnt > 0; --i) {
            if (arr[i] == 0) continue;

            int times = min(arr[i], cnt);
            cnt -= times;
            val2 *= pow(i - 1000, times);
            if (last == INT_MAX) {
                last = i - 1000;
            }
        }

        val1 *= last;
        return max(val1, val2);
    }
};
```