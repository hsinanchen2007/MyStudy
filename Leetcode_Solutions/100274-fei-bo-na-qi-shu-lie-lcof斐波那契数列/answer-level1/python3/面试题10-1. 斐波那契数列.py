```java []
class Solution {
    public int fib(int n) { // DP
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int first = 0, sec = 1;
        int sum = 0;
        for(int i = 2; i <= n; i++){
            sum = first + sec;
            first = sec;
            sec = sum % 1000000007;
        }
        return sec;
    }
}
```
```python []
class Solution:
    def fib(self, n: int) -> int: # DP
        if n == 0:
            return 0
        if n == 1:
            return 1
        first = 0
        sec = 1
        for i in range(2, n + 1):
            first, sec = sec, (first + sec) % 1000000007
        return sec
```
