### 解题思路
a 偶数位
b 奇数位
a左移1位，b右移1位，这样就完成了交换
每次都修改0的这2位
（&操作取某一位，|操作修改某一位，大学未学好移位操作，求大神们指点）



### 代码

```java
class Solution {
    public int exchangeBits(int num) {
        int ans = 0;
        for (int i = 0; i < 32; i += 2) {
            int a = num & (1 << i);
            int b = num & (1 << (i + 1));
            ans |= (a << 1);
            ans |= (b >> 1);
        }
        return ans;
    }
}
```