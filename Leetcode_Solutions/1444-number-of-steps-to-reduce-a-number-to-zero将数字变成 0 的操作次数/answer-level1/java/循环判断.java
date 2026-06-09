### 解题思路


### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int step = 0;
        while (num != 0) {
            step++;
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
        }
        return step;
    }
}
```