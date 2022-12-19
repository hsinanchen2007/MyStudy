### 解题思路
不能使用if-else或其他比较运算符，因此我们转换思路，根据两数相减的正负号来判断大小关系

根据两数相减的正负号来判断大小关系可能又要用到if-else，再次转换思路，使用两数相减结果的二进制表示的首位来判断正负

首位只有0，1两种可能，对于a - b，存在两种可能
首位为0，则a >= b return a
首位为1，则a < b return b
则可以创建array = {a, b}
并且return array[首位数值]

现在我们需要设法拿到首位数值，可以使用&运算屏蔽其他位，即(((long)a - b) & 0x8000000000000000L)
现在我们需要将得到的数值转换为数组的index，使用无符号移位，即>>> 63

注意：这里必须使用long，因为a - b可能数值过大,int无法表示

### 代码

```java
class Solution {
    public int maximum(int a, int b) {
        int[] array = {a, b};
        return (int)array[(int)((((long)a - b) & 0x8000000000000000L) >>> 63)];
    }
}
```