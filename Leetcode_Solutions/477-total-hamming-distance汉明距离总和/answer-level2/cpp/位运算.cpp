# 思路一

遍历所有的两两组合，计算汉明距离之和，时间复杂度是 $\mathcal O(n^2)$，数组的最大尝试是 $10^4$，数据量比较庞大，很容易超时。

```cpp
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        long long z = (x ^ y);
        int ret = 0;
        while (z != 0) {
            z = (z & (z - 1));
            ret++;
        }
        return ret;
    }

    int totalHammingDistance(vector<int>& nums)
    {
        int ret = 0, n = nums.size();
        // 遍历所有的两两组合
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ret += hammingDistance(nums[i], nums[j]);
            }
        }
        return ret;
    }
};
```

# 思路2

统计每个二进制位 `1` 的个数和 `0` 的个数, 按照每个二进制位的不同将数组分为两组；一组是第 `i` 位为 `1`，一组是第 `i` 位为 `0`; 数据的两两组合表示为这两组数据之间的全排列 即其个数相乘

- 按位操作总共遍历32次，时间复杂度是 $\mathcal O(32 * n) = \mathcal O(n)$

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        int n = nums.size(), ret = 0;
        unsigned int mask = 1;
        for (int i = 0; i < 32; i++) {
            int cnt1 = 0; // 当前位是1的数值个数
            for (const int& num : nums) {
                if (num & mask)
                    cnt1++;
            }
            ret += cnt1 * (n - cnt1);
            mask <<= 1; // 表示下一位是否是 1
        }
        return ret;
    }
};
```