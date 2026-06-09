### 解题思路
1. 利用递归的思想；
2. 当`N`为`0`或`1`时，返回自身的值；
3. 当`N`大于`1`时，返回`fib(N-2)+fib(N-1)`的值
### 代码

```java
class Solution {
    public int fib(int N) {
        if (N == 0 || N == 1) {
			return N;
		} else {
			return fib(N - 1) + fib(N - 2);
		}
    }
}
```