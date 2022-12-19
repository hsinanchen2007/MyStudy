### 解题思路
A*B的定义就是B个A相加的和，所以A*B=A+A*(B-1)；题目要求用递归实现，直接用循环更简单直观。

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        if(B == 0) return 0;
        return A + multiply(A, B - 1);
    }
}
```