### 解题思路
执行用时:12 ms,在所有 cpp 提交中击败了32.49%的用户
内存消耗 :8.2 MB,在所有 cpp 提交中击败了69.11%的用户
### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        return N==0||N==1 ? N : (N==1 ? 1:fib(N-1)+fib(N-2));
    }
};
```