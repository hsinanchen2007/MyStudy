[268_缺失数字 题解](https://github.com/luo-rong/LeetCode/tree/master/src/_268_MissingNumber) / [GitHub 持续更新](https://github.com/luo-rong/LeetCode)

1. 方法1：0-n的总和减去数组中出现的数，即可得到未出现的数字。求和过程和减去出现数字的过程可合并操作
2. 方法2：位运算，异或。将0-n和nums数组中的数字合并（共2n+1个数），可以将问题转化为：除了一个数字外，其余数字均出现两次，求只出现一次的数字。可以用异或运算（相同为0，不同为1）找到目标数

```java
public class MissingNumber {
    // 方法1
    public int missingNumber1(int[] nums) {
        int missingNum = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            missingNum = missingNum - nums[i] + i;
        }
        return missingNum;
    }

    // 方法2
    public int missingNumber(int[] nums) {
        int missingNum = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            missingNum = missingNum ^ nums[i] ^ i;
        }
        return missingNum;
    }
}
```