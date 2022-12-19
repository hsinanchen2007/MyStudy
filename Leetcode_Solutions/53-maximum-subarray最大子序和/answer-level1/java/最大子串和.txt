### 解题思路
一个变量result保存结果，初始化为数组第一个元素
一个变量sum用来求和，初始化为0
遍历一遍数组：
    sum如果大于0，和当前元素相加
    sum如果小于0，则说明这段子串和后面的任意数字加都会让其变小，则把sum赋值为当前元素
    最后和result比较，result保存大的值
循环结束result为最大子串值

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            result = result>sum?result:sum;
        }
        return result;
    }
}
```