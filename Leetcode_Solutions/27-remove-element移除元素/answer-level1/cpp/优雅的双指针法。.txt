### 解题思路
双指针法：k 表示慢指针，i 表示快指针，遍历数组，将不等于 val 的元素保存在数组的 k 位置上，直到遍历结束。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() < 1) {
          return 0;
        }

        if (nums.size() == 1) {
          if (nums[0] == val) {
            return 0;
          } else {
            return 1;
          }
        }

        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
          if (nums[i] == val) {
            continue;
          } else {
            nums[k++] = nums[i];
          }
        }

        return k;
    }
};
```