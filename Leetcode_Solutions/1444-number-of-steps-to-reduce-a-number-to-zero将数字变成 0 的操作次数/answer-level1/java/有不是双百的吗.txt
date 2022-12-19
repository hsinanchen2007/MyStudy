### 解题思路
没什么

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
    int step = 0;
        while (num != 0) {
            if (num % 2 == 0)
                num >>= 1;
            else
                num -= 1;
            step++;

        }

        return step;
    }
}
```