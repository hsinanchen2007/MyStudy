### 解题思路
可以发现第i个数和是由前一行第(i+1)/2个数得来的，所以我们去判断这个数的根源。最开始N=1是0，那么下面第1个数是0，第二个数是1，所以由0得来的数可以表示为(k + 1) % 2，由1得来的数可以表示为K % 2。

### 代码

```cpp
class Solution {
public:
  int kthGrammar(int N, int K) {
    if (N == 1)
        return 0;
    if (kthGrammar(N - 1, (K + 1) / 2) == 0)
        return (K + 1) % 2;
    else
        return K % 2;
    }
};
```