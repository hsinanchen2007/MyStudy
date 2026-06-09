### 解题思路

非递归法：

### 代码

```java
class Solution {
    public int fib(int N) {

       if(N <= 1) return N;
        //0 1 1 2 3 5 8 13 21 34......
        int first = 0;
        int second = 1;
        for(int i = 0; i < N -1; i++){
            second = first + second;
            first = second - first;
        }

        return second;
    }
}
```