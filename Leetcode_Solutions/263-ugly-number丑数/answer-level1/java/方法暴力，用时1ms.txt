### 解题思路
依次将因子2，3，5提取出来，每次提取将原数除以对应的因子，提取完如果原数变为一，则为“丑数”，
如果不是一那说明还有其他因子，不是“丑数”。

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if (num < 1) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        while (num % 2 == 0) {
            num = num / 2;
        }
        while (num % 3 == 0) {
            num = num / 3;
        }
        while (num % 5 == 0) {
            num = num / 5;
        }
        if (num == 1) {
            return true;
        }else {
            return false;
        }
    }
}
```