### 解题思路
令函数f(n,m)返回长度为n的序列计算后最后一个元素的序号（即正确解）
则f(n-1,m)也能够返回长度为n-1序列计算后的最后一个元素的序号
只需要理清f(n,m),f(n-1,m)之间的关系即可完成递归
对于长度为n的序列f(n,m)，我们删除了第m%n个元素，剩下的元素构成一个n-1序列，令这个n-1序列的解为
x，即f(n-1,m)=x，可以看出来没删除该元素时解为(m+x)%n

### 代码

```cpp
class Solution {
    int f(int n, int m) {
        if (n == 1)
            return 0;
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};
```