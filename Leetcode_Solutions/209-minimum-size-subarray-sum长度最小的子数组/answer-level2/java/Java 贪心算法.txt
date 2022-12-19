### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (null == nums || 0 == nums.length)
            return 0;

        int tmpSum = 0;
        int begin = 0;
        int end = 0;
        int step = -1;

        while (true) {

            if (tmpSum < s) {
                if (end == nums.length)
                    break;
                tmpSum += nums[end];
                ++end;
                continue;
            }

            if (-1 == step)
                step = end - begin;
            System.out.println("begin: " + begin + "  end: " + end);
            step = Math.min(step, end - begin);
            tmpSum -= nums[begin];
            ++begin;
        }
        return step == -1? 0: step;
    }
}
```