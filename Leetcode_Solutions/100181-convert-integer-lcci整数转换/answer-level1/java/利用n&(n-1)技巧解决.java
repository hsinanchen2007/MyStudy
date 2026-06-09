### 解题思路
即求A与B异或的值中1的个数, 通过n&(n - 1)可以去掉一个数的二进制表示的最右边的1.
如下原理: 

```
     xxx100  (n)
  &  xxx011  (n - 1)
     xxx000
```
### 代码

```java
class Solution {
    public int convertInteger(int A, int B) {
        int temp = A ^ B;
        int count = 0;
        while (temp != 0) {
            temp &= (temp - 1);  // 去掉二进制表示的最右边的1
            count++;
        }
        return count;
    }
}
```