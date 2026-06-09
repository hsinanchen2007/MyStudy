### 解题思路
0~n-1中，第1个删掉的数是(m%n-1)

删掉后剩下的队列：
0, 1, 2, ...(m%n-2), (m%n), (m%n+1), (m%n+2), ..., n-1

下一次从m%n开始计数，
(m%n), (m%n+1), (m%n+2), ..., n-1, 0, 1, 2, 3, ...(m%n-2)
后面的0~(m%n-2)可以都加上n，
(m%n), (m%n+1), (m%n+2), ..., n-1, n, (n+1), (n+2), (n+3), ...(n+m%n-2)
所有值都减去m%n，队列可以变为：
0,1,2,3...,n-2,
即f(n-1,m)。
(m%n), (m%n+1), (m%n+2), ..., n-1, n, (n+1), (n+2), (n+3), ...(n+m%n-2)
对应的最后1个值为f(n-1,m)+m%n.

(m%n), (m%n+1), (m%n+2), ..., n-1, 0, 1, 2, 3, ...(m%n-2)
最后剩下的值为：
(f(n-1,m)+m%n >=n) ? (f(n-1,m)+m%n - n) ? (f(n-1,m)+m%n)

所以递推关系是：
f(n,m) = (f(n-1,m)+m%n >=n) ? (f(n-1,m)+m%n - n) ? (f(n-1,m)+m%n)




### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int t = lastRemaining(n-1, m) + m%n;
        if (t >= n) {
            return t-n;
        } else {
            return t;
        }
    }
};
```