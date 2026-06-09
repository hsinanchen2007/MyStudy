### 解题思路
这种题目真的无聊，其实就是数学+位运算，但是懒得写。。。

### 代码

```java
class Solution {
    public boolean isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }

        return (Math.log10(n) / Math.log10(4)) % 1 == 0;
    }
}
```