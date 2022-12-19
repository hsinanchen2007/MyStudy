### 解题思路
从起点（start）开始，判断起点能到达的点(reach)中，reach能到达的最远位置furthest。以最远的reach作为下次的start。

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if (nums.length <= 1) return 0;
        if (nums[0] == 0) return 0;

        int start = 0; // 当前的起点
        int furthest = 0; //当前起点能达到的点中下次跳跃能达到的最远位置
        int reach = 0; // 能跳到furthest的点
        int step = 1; // 跳跃步数
        while (furthest < nums.length - 1) {
            if (start + nums[start] >= nums.length - 1) break;
            for (int i = 1; i <= nums[start]; i++) {
                if (nums[start + i] + start + i > furthest) {
                    furthest = nums[start + i] + start + i;
                    reach = start + i;
                }
            }
            start = reach;
            step++;
        }
        return step;
    }
}
```