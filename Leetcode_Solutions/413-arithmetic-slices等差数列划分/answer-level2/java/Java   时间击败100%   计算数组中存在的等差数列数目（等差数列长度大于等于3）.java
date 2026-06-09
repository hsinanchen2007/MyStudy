### 解题思路
通过测试用例不通过不断调整，最终通过！！！
具体思路见代码注释。（写给自己的，不知道以后自己能否看得懂-.-）

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A.length < 3) {
            return 0;
        }
        int count = 0;
        int val = A[1] - A[0]; // 差值
        int start = 0, end = 1;
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == val) {
                // 如果差值相等，则end向后移动一个，同时检查是否达到长度大于等于3
                end++;
                // 长度其实应该用表达式：end - start + 1 >= 3 经过简化则如下
                // 对于下面count变化的过程其实是通过几个特殊用例发现的规律
                // 等差数列为3个，则此时count+1；等差数列又增加一个元素（即4），此时count在原来3长度基础上需要+2；
                // 等差数列又增加一个，此时count在原来4长度的基础上需要+3；因此count += end - start - 1；
                // 随着长度变长，比上一次加的也就增加1，因此通过start和end的间距变化得到上面的表达式
                if (end - start >= 2) {
                    count += end - start - 1;
                }
            } else {
                // 差值与上一次的不一样，则此时需要更新start和end，同时更新差值
                start = i - 1;
                end = i;
                val = A[i] - A[i - 1];
            }
        }

        return count;
    }
}
```