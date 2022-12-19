### 解题思路
1、首先将数组按照升序进行排序
2、利用前三个数的和作为最小minGap的初始值，维护一个双指针，头指针指针指向第二个数，尾指针指向最后一个数
3、计算第一个数（index）和两个指针指向的数字的之和与target之间的gap,如果gap等于0，直接返回三数之和，入股小于0，头指针向后挪一个位置（++），如果大于0，则尾指针向前挪一个位置（--），同时计算比较gap的绝对值和minGap的绝对值的大小，如果gap小于minGap，刷新minGap,一次类推，指导头指针和尾指针重合
4、第一个数向后遍历，知道遍历完整个数组

### 代码

```java
import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int sum = 0;
        if (nums.length <= 3) {
            for (int num : nums) {
                sum += num;
            }
            return sum;
        }
        Arrays.sort(nums);
        int leastDeta = nums[0] + nums[1] + nums[2] - target;
        for (int i = 0; i < nums.length - 2; i++) {
            int startIndex = i + 1;
            int endIndex = nums.length - 1;
            while (startIndex < endIndex) {
                int tempSum = nums[i] + nums[startIndex] + nums[endIndex] - target;
                if (tempSum == 0) {
                    return target;
                } else if (tempSum < 0) {
                    startIndex++;
                    if (Math.abs(tempSum) < Math.abs(leastDeta)) {
                        leastDeta = tempSum;
                    }
                } else {
                    endIndex--;
                    if (tempSum < Math.abs(leastDeta)) {
                        leastDeta = tempSum;
                    }
                }
            }
        }
        return leastDeta + target;
    }
}
```