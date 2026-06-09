### 解题思路

和官方题解思路一致，只是代码中的变量名的区别。
很疑惑，执行用时和内存消耗都不太理想，你们还有高招？

执行用时 :80 ms, 在所有 C++ 提交中击败了17.76%的用户
内存消耗 :25.6 MB, 在所有 C++ 提交中击败了5.69%的用户

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int from = 0;
        int to = nums.size() - 1;
        int index = 0;
        
        while (from <= to) {
            index = from + (to - from) / 2;

            if (target == nums[index]) {
                return index;
            } else if (target > nums[index]) {
                from = index + 1;
            } else {
                to = index - 1;
            }
        }
        return -1;        
    }
};
```