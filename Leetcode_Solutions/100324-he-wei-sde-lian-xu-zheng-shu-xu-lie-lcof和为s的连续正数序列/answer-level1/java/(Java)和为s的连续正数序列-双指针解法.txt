### 解题思路
1. 构建双指针代表连续正数序列的首尾并初始化，通过观察发现满足要求的结果结果连续且不重复，因此初始化start = 1，end = 2
2. 双指针的框架就是while循环，start < end
3. 然后分析连续正数序列求和就是一个等差数列求和，因此可得公式value = (start + end) * (end - start + 1) / 2
4. 如果刚好value == target，就把从start到end放入解中
5. 如果value < target，说明序列和过小，只能通过增加end来增大。
6. 如果value > target，说明序列和过大，只能通过增加start来减小。
7. 如果value == target，不要忘了增加end来保持指针移动。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        int start = 1;
        int end = 2;
        while (start < end) {
            int value = (start + end) * (end - start + 1) / 2;
            if (value < target) {
                end++;
            } else if (value > target) {
                start++;
            } else {
                int[] r = new int[end - start + 1];
                int t = start;
                for (int i = 0; i < r.length; i++) {
                    r[i] = t;
                    t++;
                }
                res.add(r);
                end++;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```