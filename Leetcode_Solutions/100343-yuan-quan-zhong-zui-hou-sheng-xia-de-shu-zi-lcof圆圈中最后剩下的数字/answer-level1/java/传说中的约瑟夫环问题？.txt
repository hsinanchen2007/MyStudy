### 解题思路
约瑟夫环问题，利用递推公式求解

**递推公式
`lastRemaining(n, m) = ( lastRemaining(n-1, m) + m ) % n`**

函数`lastRemaining(n, m)`表示在有`n`个小盆友时，最终存活的那个小盆友的编号
可以理解为砍死一个小盆友后，会从砍死的小盆友的下一位开始重新编号，新编号较之之前的少了`m`
以`n = 5, m = 3`为例，第一轮砍死小盆友`2`，下一轮从他之后的小盆友`3`开始，小盆友`3`重编成了小盆友`0`，与之前相差了`m`
因为是一个环，所以要再对列长`n`取个模

在还剩两个小盆友的时候，结束递归：
如果`m`是奇数，则砍死小盆友`0`，小盆友`1`最终存活
如果`m`是偶数，则砍死小盆友`1`，小盆友`0`最终存活

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n == 2) {
            if(m % 2 == 0) {
                return 0;
            } else {
                return 1;
            }
        }
        return (lastRemaining(n-1, m) + m) % n;
    }
}
```