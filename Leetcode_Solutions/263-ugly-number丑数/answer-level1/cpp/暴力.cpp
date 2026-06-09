### 解题思路
不断循环除以2、3、5，如果最后的结果不等于1则说明不是丑数。

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if (num == 0) return false;
        while (num%2==0 || num%3==0 || num%5==0) {
            if (num%2==0) num /= 2;
            if (num%3==0) num /= 3;
            if (num%5==0) num /= 5;
        }
        return num == 1;
    }
}
```