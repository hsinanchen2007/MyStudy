## 思路一：累加和
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        return (1 + size) * size / 2 - sum;
    }
};
```

## 思路二：异或运算（最优解）
**无进位相加**
- 任何数与本身异或为0
- 任何数与0异或为本身
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (nums[i]^i);
        }
        return res;
    }
};
```
