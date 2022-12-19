### 解题思路
一开始是用递归写的，用时10ms

后来改用替换，因为只求一个N对应的值，所以不需要保存过程。

也可以考虑保存过程，用数组保存每个数字，然后直接相加最后两个数字

### 代码

```java
class Solution {
    public int fib(int N) {
        if(N <= 1)
            return N;
        
        int x = 0, y = 1, z = 1, i = 0, end = N - 2;
        
        while(i <= end){
            z = x + y;
            x = y;
            y = z;
            i++;
        }
        
        return z;
    }
}
```