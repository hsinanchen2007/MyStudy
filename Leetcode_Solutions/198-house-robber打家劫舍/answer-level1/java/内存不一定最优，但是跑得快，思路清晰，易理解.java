### 解题思路

1. 当数组长度为1的时候，直接返回当前值
2. 当数组长度为2的时候，直接返回下标为0与1的max
3. 建立一个新的数组用来存放累计到改天的最大金额，例如total[0],代表了第一天的最大值，肯定是nums[0],
   而到第二天为止的最大值肯定是Max（nums[0]，nums[1]) 因为第一第二天不能连续选，所以第二天要么继承第一天，要么就是自己
4. 重点：到了第三天，可以用同样的思路去理解，首先不可能连续选择，那剩下的就是两种可能：
   1. 取第四天的nums + 第2天的total
   2. 继承第三天的total即可
   正确选项就是取2种可能的max()，设置为第三天的total,接下来以此类推，我们就可以得到正确答案。

![image.png](https://pic.leetcode-cn.com/8b135d45792bb99f34a6fee5ee2769447b1be9fd0cd0a61a758577fd27f9ff5a-image.png)

### 代码

```java
public class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        if(nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] total = new int[nums.length];
        total[0] = nums[0];
        total[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < total.length; i++) {
            total[i] = Math.max(total[i - 1], nums[i] + total[i - 2]);
        }
        return total[nums.length - 1];
    }
}
```