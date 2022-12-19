### 解题思路
1. 递推方法：依次将前两个数的值赋值给他们的下一位

### 代码

```java
class Solution {
   //递推方法
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int f1 = 1;
            int f2 = 2;
            int f3 = 0;
            for (int i=2; i<n; i++) {
               f3 = f2 + f1;
               f1 = f2;
               f2 = f3;
            }
            return f3;
        }

    }
}
```