### 解题思路

思路：
1、很明显的滑窗法，固定窗口中0的个数就行了，不想优化了

116ms 51.7M
--- wangtao HW-2020/4/1

### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int left = 0;
        int right = 0;

        int count = 0;
        while (right < A.size()) {
            if (A[right] == 1) {
                right++;
                continue;
            } else {
                count++;
            }
            right++;
            while (count > K) {
                ans = max(ans, right - left - 1);
                if (A[left] == 0) {
                    count--;
                }
                left++;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};
```