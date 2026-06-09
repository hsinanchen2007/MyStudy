### 解题思路

题目中说明了有两种字符串类型，第一种是0，第二种是10和11。我们把输入的数组看成一个栈，下标的位置则为栈顶的位置，所以当bits[i] == 1，i += 2。相当于直接连续出栈两个数字，如果bits[i] == 0 && 是数组最后一位的时候，直接返回true。

### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int count = 0;
        for (int i = 0; i < bits.length; i++) {
            if (bits[i] == 1) {
                i ++;
                continue;
            }
            if (bits[i] == 0 && i == bits.length - 1) {
                count ++;
            }
        }
        return count > 0;
    }
}
```