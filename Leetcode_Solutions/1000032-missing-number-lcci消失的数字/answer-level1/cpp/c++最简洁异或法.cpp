### 异或法
利用异或位运算性质可在O(n)内完成（与第268题相同）

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = size;
        for (int i = 0; i < size; i++) {
            res ^= (i ^ nums[i]);
        }
        return res;
    }
};
```
![2020-02-14_10-43.png](https://pic.leetcode-cn.com/b871880ea0fa7a7db5b137130c81dfe92cacab917e7831b1f3089c3017dcb2e8-2020-02-14_10-43.png)
