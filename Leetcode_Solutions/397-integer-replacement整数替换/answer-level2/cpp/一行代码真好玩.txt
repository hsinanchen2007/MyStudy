### 解题思路
除3外，二进制整数最后两位是11则+1，是01则-1
### 代码

```cpp
class Solution {
public:
    int integerReplacement(int n) {
        return n==1 ? 0 : n==2147483647? 32:n==3?2:(n&1? (n&2 ?integerReplacement(n+1)+1:integerReplacement(n-1)+1 )  :integerReplacement(n/2)+1);
    }
};
```