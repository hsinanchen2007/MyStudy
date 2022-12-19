### 解题思路

从最左边开始遍历求和，找到满足条件的数组停下，没有则返回0，遇到值刚好大于等于指定值，返回1

这时从最左边开始缩减数组长度 使之能够满足 条件， 缩减完成后继续轮询

继续轮询：像窗口一样滑动，每次去掉最左边的值，加上右边的值 

然后缩减左边的长度 使之能满足条件，缩减完继续轮询直到结束


### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int result = 0;
        int sum = 0;
        boolean flag = true;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= s) {
                return 1;
            }
            if (flag) {
                sum += nums[i];
                if (sum >= s) {
                    result = i + 1;
                    flag = false;
                    for (int j = 0; j < i; j++) {
                        if (sum - nums[j] >= s) {
                            result --;
                            sum = sum - nums[j];
                        } else {
                            break;
                        }
                    }
                }
            } else {
                sum = sum - nums[i - result] + nums[i];
                if (sum >= s) {
                    for (int j = result - 1; j > 0; j--) {
                        if (sum - nums[i - j] >= s) {
                            sum = sum - nums[i -j];
                            result --;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
}
```