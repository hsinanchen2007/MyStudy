### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户



### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        return func(num);
    }

    public boolean func(double num) {
        // 排除不能整除的情况
        if (num > (int) num) return false;
        if (num == 2 || num == 3 || num == 5) return true;
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) return false;
        return func(num / 2) || func(num / 3) || func(num / 5);
    }
}
```