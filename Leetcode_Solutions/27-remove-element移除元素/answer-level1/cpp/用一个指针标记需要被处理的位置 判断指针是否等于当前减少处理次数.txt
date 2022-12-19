### 解题思路
标记指针j和遍历指针i同时从nums[0]出发。
移动过程中有两种情况：
1. nums[i] == val i不做处理挪向下一位，j停在这个位置。
2. nums[i] != val j已经标记了上一个需要被处理的位置，于是将nums[i]赋值给nums[j]，j挪向下一位。i的下一位如果还是非val的值，nums[j]也是非val的值，依然执行nums[j] = nums[i]。因为i从头到尾遍历，保证它会将访问过的每一个值都赋值给前面的某个entry。所以nums[j]的值不会因为被覆盖而丢失。
特殊情况：数组中没有要被删除的值。以上写法会导致自己给自己赋值，于是在赋值前判断i和j是否相等，如果相等只把j向后挪一位，即和i一起到达下一位。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] != val) {
                if (i != j) nums[j++] = nums[i];
                else ++j;
            }
        }
        return j;
    }
};
```