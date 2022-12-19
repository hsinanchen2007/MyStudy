### 解题思路
这是一道非常典型的使用递归的例子，当N<2时我们依次赋值，当N>2时，我们不断循环调用该函数方法，最后会归为0和1的方法。

### 代码

```java
class Solution {
    public int fib(int N) {
        if(N==0) {
            return 0;
        }
        if(N==1) {
            return 1;
        }
        return fib(N-1)+fib(N-2);
    }
}
```