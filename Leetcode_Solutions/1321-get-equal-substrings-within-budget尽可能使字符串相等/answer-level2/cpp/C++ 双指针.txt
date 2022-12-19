### 解题思路
双指针 需要循环两边。。感觉比较蠢

### 代码

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int size = s.size();
        int res  = 0;
        vector<int> diff(size, 0);

        for (int i = 0; i < size; i++) {
            diff[i] = abs(s[i] - t[i]);
        }

        int start;
        int end = 0, sum = 0;
        for (int start = 0; start < size; start++) {
            while (end < size && sum + diff[end] <= maxCost) {
                sum += diff[end];
                end++;
            }

            res = max(res, end - start);
            sum -= diff[start];
        }

        return res;
    }
};
```