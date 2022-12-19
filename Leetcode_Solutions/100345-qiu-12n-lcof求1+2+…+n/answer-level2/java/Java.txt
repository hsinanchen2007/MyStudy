### 解题思路
不能循环就递归，&&短路
n>0,需要执行递归n+=n-1;
n=0,不需要执行后面的语句
Java要按照&&前后为boolean类型

### 代码

```java
class Solution {
    public int sumNums(int n) {
        boolean b=(n > 0) && ((n += sumNums(n - 1)) > 0);
        return n;
    }
}
```