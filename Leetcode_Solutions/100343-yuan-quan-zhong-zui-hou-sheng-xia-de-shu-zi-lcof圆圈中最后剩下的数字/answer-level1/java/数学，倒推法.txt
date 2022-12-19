### 解题思路
从最后一个索引0开始逐个向前推导前一次的索引

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int index = 0;
        for (int i = 2; i <= n; i++) {
            index = (index + m) % i;
        }
        return index;
    }
}
```