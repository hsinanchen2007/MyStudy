### 解题思路
遍历数组，将不同的元素存储在 k 位置，k 每次加一，相同的元素直接过滤掉。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() < 2) {
        return nums.size();
      }

      int k = 0;

      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[k]) {
          continue;
        } else {
          nums[++k] = nums[i];
        }
      }

      return ++k;
    }
};
```