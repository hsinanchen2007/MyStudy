### 解题思路
a和b都可以由32位二进制数来表示，所以m和n分别记录对应的a和b在某一位上为零还是为一，然后相加，如果取余为1，则最后的和sum在该位上也为1，和mask取或便可以得到sum在该位置为1，如果取余为零，则不用作任何操作。res表示的是进位，除以2即可。双百分百，简单明了。

### 代码

```java
    class Solution {
        public int add(int a, int b) {
            int sum = 0;
            int res = 0;
            for (int i = 0;i < 32;i++) {
                int mask = 1 << i;
                int m = (a & mask) == mask ? 1 : 0;
                int n = (b & mask) == mask ? 1 : 0;
                if((res + m + n) % 2 == 1) sum |= mask;
                res = (res + m + n) / 2;
            }
            return sum;
        }
    }
```