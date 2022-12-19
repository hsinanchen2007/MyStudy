
双指针比较适合数组中所有元素都是正数的情况。所以看到数组中如果所有元素都是正数，先想想双指针能否解决。

有一些奇怪的 case:

```
0
[2,3,1,2,4,2]
```

如果 s 的值是 0，最后输出的最小长度也是 1 而不是 0。为了保持和官方输出一致，因此你会看到一个 i == j 的判断条件，至少保证有一个元素。

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0, j = 0, sum = 0, res = INT_MAX;
        while (j < nums.size()) {
            if (i == j || sum < s) {
                sum += nums[j++];
            } else {
                res = min(res, j - i);
                sum -= nums[i++];
            }
        }
        while (s <= sum && i < j) {
            res = min(res, j - i);
            sum -= nums[i++];
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
