### 解题思路
此处撰写解题思路

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