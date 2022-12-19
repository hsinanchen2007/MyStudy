### 解题思路

只需要预处理一下N = 0,1,2的三种特殊情况，后面的所有情况，利用一个变量，用于存储结果前的一个数，始终让temp跟着result，这样不需要递归，也不需要额外的数组开销。感觉效率提高很多~~~~各位怎么看？？欢迎评论~~
### 代码

```java

class Solution {
    public int fib(int N) {
        if (N < 2) {
            return N;
        }
        if (N == 2){
            return 1;
        }
        int temp = 1;
        int result = 1;
        for (int i = 3; i <= N ; i++) {
            result= temp + result;
            temp = result - temp;
        }
        return result;
    }
}
```