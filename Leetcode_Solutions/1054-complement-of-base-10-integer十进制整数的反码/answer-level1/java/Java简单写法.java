### 解题思路
先左移再或运算，获取全是1的数，再进行异或

### 代码

```java
class Solution {
    public int bitwiseComplement(int N) {
        int num = 1;

        while (true) {
            if (num >= N) return num ^ N;
            else num = (num << 1) | 1;
        }
    }
}
```