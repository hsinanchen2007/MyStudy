## 思路一：摩尔投票
先假设第一个数为超过半数，然后与下一个数进行比较，如果相等，则计数器加一，否则计数器减一，如果计数器值为0，则假设新的超过半数的数为当前数并重置计数器值为1。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == res) ++cnt;
            else --cnt;
            if (cnt == 0) {
                cnt = 1;
                res = nums[i];
            }
        }
        return res;
    }
};
```

## 思路二：位运算
对目标数按位进行建立，从0到31位，每次统计数组中每个数在该位上0和1的个数，如果1多，则将结果res的该位上变为1，最后累加出来的res即为目标数。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, size = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > size / 2 || zeros > size / 2) break;
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};
```
