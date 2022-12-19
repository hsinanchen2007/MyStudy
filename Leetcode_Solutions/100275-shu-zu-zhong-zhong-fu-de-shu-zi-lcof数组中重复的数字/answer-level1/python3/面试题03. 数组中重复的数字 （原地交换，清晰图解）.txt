#### 解题思路：

> 寻找数组中的重复数字，直接想到的方法是遍历数组，并使用 HashMap 统计每个数字的数量，遇到数量大于 $1$ 的数字则返回。此方法时间复杂度和空间复杂度均为 $O(N)$ 。

- 题目中指出 `在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内` 。 因此，我们可以利用数组下标作为 HashMap 的 key ，具体实现方法是遍历数组并通过交换操作使索引与值一一对应，（即 `nums[i] = i` ），这样就能通过索引找到对应值。

- **算法原理：** 
  - 遍历数组，每次遇到索引为 `i` 的新数字 `nums[i]` 时，将其交换至索引为 `nums[i]` 的 `nums[nums[i]]` 处。
  - 而当遍历遇到一个重复数字 `x` 时，一定有 `nums[x] == x` （因为第一次遇到 `x` 时已经将其交换至 `nums[x]` 处了）。利用以上方法，即可得到一组重复数字。

- **算法流程：** 
  - 遍历数组 `nums` ，设索引初始值为 `i = 0`:
    1. **若 `nums[i] == i` ：** 说明此数字已在对应索引位置，无需交换，因此执行 `i += 1` 与 `continue` ；
    2. **若 `nums[nums[i]] == nums[i]` ：** 说明索引 `nums[i]` 处的元素值也为 `nums[i]`，即找到一组相同值，返回此值 `nums[i]`；
    3. **否则：** 当前数字是第一次遇到，因此交换索引为 `i` 和 `nums[i]` 的元素值，将此数字交换至对应索引位置。
  - 若遍历完毕尚未返回，则返回 $-1$ ，代表数组中无相同值。

#### 复杂度分析：

- **时间复杂度 $O(N)$ ：** 遍历数组使用 $O(N)$ ，每轮遍历的判断和交换操作使用 $O(1)$ 。
- **空间复杂度 $O(1)$ ：** 使用常数复杂度的额外空间。

<![Picture9.png](https://pic.leetcode-cn.com/e1094d225ad207483dab4f9df3fe6c89c106ad2c1c7ebb77c0bcd439d014e764-Picture9.png),![Picture1.png](https://pic.leetcode-cn.com/5368f5db2b57fc6530dcfd01ba2be2f026f3afba89ec1006e87acb0cf96fb9f6-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/01fd44dc5603fbf0617589642f618aa9cdb8a2760b3a71b53bb9f2a7b330777e-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/42720b92d058c6c30c37a850a19c03dce949041479960e7da0311a9b57a02c30-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/b64e5dd58a70cb9f31a9222c7f4019b28d9d2479e9434138affefbd61fa3ea4b-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/0b94c6c8b4c00d9ea8f60653e80893849c4288d7b047c0872cdbd9e5931604bc-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/6ff15655734d367ac590520d9f20b8cc2e538452592c68857c57c1fe954707d1-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/d201a780df2b28baed9beed9376e5a8fb6e4a3b978464eca94139c446188d0bb-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/27b8cc4d044c493047e7ef4f6c128c8711f25701fc4e7c0d94d39c0165fcf3e5-Picture8.png)>

#### 代码：

```python []
class Solution:
    def findRepeatNumber(self, nums: [int]) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]: return nums[i]
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1
```

```java []
class Solution {
    public int findRepeatNumber(int[] nums) {
        int i = 0;
        while(i < nums.length) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i]) return nums[i];
            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
        return -1;
    }
}
```
