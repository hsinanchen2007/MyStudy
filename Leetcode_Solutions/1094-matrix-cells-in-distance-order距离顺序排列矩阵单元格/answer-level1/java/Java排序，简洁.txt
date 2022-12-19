### 解题思路
先构建数组，然后进行排序，代码简洁

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] nums = new int[R * C][2];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                nums[i * C + j][0] = i;
                nums[i * C + j][1] = j;
            }
        }

        Arrays.sort(nums, (o1, o2) -> Math.abs(o1[0] - r0) + Math.abs(o1[1] - c0) - Math.abs(o2[0] - r0) - Math.abs(o2[1] - c0));

        return nums;
    }
}
```