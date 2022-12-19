### 解题思路
```text
1. 贪心算法，下一跳的位置为可以使下下步到达的最远位置
2. 当前可以跳的最远位置为max(i+nums[i], nums.length - 1)
3. 从i到max(i+nums[i], nums.length - 1)中选取可以使下下步到达的最远位置为max{j+nums[j]}
```

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        // 记录步数
        int count = 0;
        // 贪心算法，从开始位置跳跃，判断下下步可以到达的最远位置
        for (int i = 0; i < nums.length - 1;) {
            int maxStep = nums[i];
            int maxDistance = i + maxStep;
            // 如果maxDistance可以到达最远位置，则停止遍历
            if (maxDistance >= nums.length - 1) {
                count++;
                break;
            }
            int nextStep = i + maxStep;
            for (int j = i + 1; j < Math.min(maxStep + i + 1, nums.length); j++) {
                if (j + nums[j] > maxDistance) {
                    maxDistance = j + nums[j];
                    nextStep = j;
                }
            }
            i = nextStep;
            count++;
        }
        return count;
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void jump() {
        int[] input1 = {2,3,1,1,4};
        int expect1 = 2;
        int result1 = solution.jump(input1);

        assertEquals(expect1, result1);

        // 出错测试用例1
        // j <  nums.length ===> j < Math.min(maxStep + i + 1, nums.length);
        int[] input2 = {2,3,1};
        int expect2 = 1;
        int result2 = solution.jump(input2);
        assertEquals(expect2, result2);

        // 出错测试用例2
        // j < Math.min(maxStep + i, nums.length); ===> j < Math.min(maxStep + i + 1, nums.length);
        int[] input3 = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
        int expect3 = 2;
        int result3 = solution.jump(input3);
        assertEquals(expect3, result3);
    }
}
```