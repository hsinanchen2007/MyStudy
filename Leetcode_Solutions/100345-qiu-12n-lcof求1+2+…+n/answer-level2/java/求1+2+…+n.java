### 解题思路
使用 && 短路的思路处理

### 代码

```java
class Solution {
    public int sumNums(int n) {
        int sum = n;
        // 使用 && 短路的思路处理
        boolean flag = n > 0 && (sum += sumNums(n - 1)) > 0;
        return sum;
    }
}
```