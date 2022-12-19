### 解题思路
其实很简单，题目要求的是返回最大的数字，那肯定是把6转成9
所以只要把第一个6转成9就是最大的数。

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        String numStr = String.valueOf(num);
        return Integer.valueOf(numStr.replaceFirst("6","9"));
    }
}
```