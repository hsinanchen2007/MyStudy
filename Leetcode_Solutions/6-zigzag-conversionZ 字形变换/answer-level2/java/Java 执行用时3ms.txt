### 解题思路
通过计算偏移位置的方式计算出下一个位置。
先计算当前行以下有多少数据计算出一个偏移，再计算当前行以上有多少数据计算出另一个偏移。
边界条件是第1行以上和最后一行以下没有数据，因此不计算偏移。
感觉这种方案不如题解精简，但是执行速度比较快，发出来有兴趣的话可以参考一下。

### 代码

```java

/**
 * 偏移位置解法
 *
 * @author 我也来试试吧
 * @since 2020-04-08
 */
class Solution {
    public String convert(String s, int numRows) {
        if (s.isEmpty() || numRows == 1) {
            // 排除num1和num2都为0的情况
            return s;
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            // 当前行之上的个数
            int nums1 = 2 * i - 1;
            // 当前行之下的个数
            int nums2 = 2 * (numRows - i - 1) - 1;

            int temp = i;
            while (temp < s.length()) {
                builder.append(s.charAt(temp));
                // 往下走，如果行以下无数据，转为往上走
                if (nums2 > 0) {
                    temp += nums2 + 1;
                    if (temp < s.length()) {
                        builder.append(s.charAt(temp));
                    }
                }
                // 往上走，如果行以上无数据，转为往下走
                temp += nums1 > 0 ? nums1 + 1 : nums2 + 1;
            }
        }
        return builder.toString();
    }
}
```