### 解题思路
此处撰写解题思路
使用两个指针，i, j;
初始：i = 0, j = n - 1;
当 i 从头向右遍历时，数组是递增有序的，当 i 增大，则 numbers[i] 增大，所以 j 必然向左移动 或 不动。因此，j 是 **单调递减**的。可将时间复杂度优化为O(2n)。

(如果numbers[i] + numbers[j] > target , 那么 numbers[i + 1] + numbers[j] 必然大于 target, 所以
当j > i  &&numbers[i] + numbers[j] > target 时 要j -- )
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0, j = n - 1; i < n; i ++)
        {
            while(j > i  && numbers[i] + numbers[j] > target) j --;
            if( numbers[i] + numbers[j] == target) return{ i + 1, j + 1 };
        }
        return { -1, -1 };
    }
};
```