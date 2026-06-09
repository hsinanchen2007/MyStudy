### 解题思路
    int f = 50;
    int g = 60;

    f = f^g;
    g = f^g;
    f = f^g;
    System.out.println(f+" "+g);
    输出结果是：60 50
    三个异或操作居然可以达到交换的效果 学习了

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i;
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }
    }
}
```