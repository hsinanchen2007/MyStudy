### 解题思路
先将两个数进行不进位的加法（即异或操作），在计算进位（即或运算）。再将两者相加（相加即重复前面的运算）

和计算机组成中的加法器有些相似。
![image.png](https://pic.leetcode-cn.com/0f25fa48c6492e84a44b05c73e3a842b2527b4a8b91f5e1c977b3f36f094e1ea-image.png)


### 代码

```java
class Solution {
    public int add(int a, int b) {
        while (b != 0) {
            int j = a ^ b;
            int k = (a & b) << 1;
            a = j;
            b = k;
        }
        return a;
    }
}
```