### 解题思路

请参考注释。

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool found = false;
        for (int i = nums.size() - 1; i > 0; --i) {
            // printf("nums[%d]=%d, nums[%d]=%d\n", i, nums[i], i-1, nums[i-1]);
            if (nums[i] > nums[i-1]) {
                // 从尾开始，先找到一个降序的位置，锁定要交换的那个数字位置为i-1
                int tmp = nums[i - 1];
                int swapIndex = i;
                // 因为此时不知道是否可以直接i-1和i位置上的数字交换，还是要和i之后位置上的数字交换哪个值是下一个最大的值
                // 比如：
                //   1,2,3 i=2时即找到一个降序的位置1(i-1), 此时直接交换1(i-1)和2(i)位置上的数字即可
                //   1,3,2 i=1时即找到一个降序的位置0(i-1), 此时因为3后面还有2，应该交换0(i-1)和2(i+1)位置上的数字
                //   2,3,1 i=1时即找到一个降序的位置0(i-1), 此时因为3后面是1，比2还小，应该交换0(i-1)和1(i)位置上的数字
                // 简单讲就是找到数字串里面那个降序的位置，然后往回找到升序位置处比当前降序位置处的数字大的那个位置，直到找到结尾处
                // 每找到一个就意味着，交换位置要后移一个位置
                for (int j = i; j < nums.size(); ++j) {
                    // 找到第一个大于nums[i-1]的数的位置直到结束位置为止
                    if (nums[i-1] < nums[j]) {
                        swapIndex = j;
                    }
                }
                // printf("swapIndex=%d\n", swapIndex);
                nums[i - 1] = nums[swapIndex];
                nums[swapIndex] = tmp;
                // 交换之后，需要将i到结尾的部分反转一下变成最小值即可
                reverse(nums.begin() + i, nums.end());
                found = true;
                break;
            }
        }
        if (!found) {
            // 找不到反转一下或者sort一下都可以
            // sort(nums.begin(), nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};
```