### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
        else if(N==1) return 1;
        else return fib(N-1)+fib(N-2);
    }
};
```