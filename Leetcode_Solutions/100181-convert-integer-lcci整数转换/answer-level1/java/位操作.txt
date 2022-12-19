### 解题思路

首先我们要知道异或操作就是不进位加法。简单来说
1 ^ 0 = 1;
1 ^ 1 = 0;
0 ^ 0 = 0;
通过上面的观察我们可以看到，某一位上面两个数字相同的结果为0，不同为1。

所以我们第一步`temp = A ^ B`。可以把相同位上的数字变为0，不同的变为1。

接下来我们就是要求temp中的1的个数，便是我们的结果。

`int lowbit = n & (-n) `则可以得到最后一个1的位置。

一个while循环求解结果即可!

### 代码

```java
class Solution {
    public int convertInteger(int A, int B) {
        int res = 0;
        int temp = A ^ B;
        while (temp!=0){
            int lowbit = temp & (-temp);
            res++;
            temp-=lowbit;
        }
        return res;
    }
}
```