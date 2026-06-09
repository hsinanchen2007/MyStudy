### 解题思路
1，先利用位运算找到这两个数
2，计算当前数组和与理论和的大小关系确定最终结果
空间复杂度 O(1)
时间负责度 O(n)

### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        int n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            n ^= (i + 1) ^ nums[i];
            sum += nums[i];
        }
        int t = n & -n;
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((i + 1) & t) {
                n1 ^= i + 1;
            } else {
                n2 ^= i + 1;
            }
            if (nums[i] & t) {
                n1 ^= nums[i];
            } else {
                n2 ^= nums[i];
            }
        }
        int k = nums.size();
        int s = (k + 1) * k >> 1;
        if (n1 > n2) {
            n1 ^= n2;
            n2 ^= n1;
            n1 ^= n2;
        }
        if (sum > s) return {n2, n1};
        return {n1, n2};
    }
};
```

![image.png](https://pic.leetcode-cn.com/6f9f38facb950bf9c2af102da2e1e283c5760474a678f121d5beb5de7dc2cb84-image.png)
