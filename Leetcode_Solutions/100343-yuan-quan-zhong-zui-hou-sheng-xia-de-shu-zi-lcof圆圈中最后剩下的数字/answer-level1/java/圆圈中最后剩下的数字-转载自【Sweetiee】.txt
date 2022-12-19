### 解题思路
以5，3为例子

o  o  o  **o**  o
o  o  x  **o**  o
         **o**  o  o  o
         **o**  o  x  o
                  o  **o**  o
                  o  **o**  x
                           o  **o**
                           x  **o**
                              **o**
从下往上推
ans表示在新的队列中的位置
ans值变化为0 1 1 0 3

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int ans = 0;
        // 最后一轮剩下2个人，所以从2开始反推
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
}
```