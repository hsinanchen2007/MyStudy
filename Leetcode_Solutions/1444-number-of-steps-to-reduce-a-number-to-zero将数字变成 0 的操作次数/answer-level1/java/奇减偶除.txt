### 解题思路
1. 循环直到 num == 0;
2. 如果是奇数，-1，如果是偶数 /2

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while (num != 0) {
            if ((num & 1) == 1) {
                num -= 1;
            } else {
                num >>= 1;
            }
            count++;
        }
        return count;
    }
}
```