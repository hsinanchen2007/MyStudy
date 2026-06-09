### 解题思路
递归的方法重点在于:1.有f(n)到f(n-1)的方法；2.有终点
常常用到的思路是，如果知道f(n-1),能否得到f(n)？

### 代码

```cpp
class Solution {
    int f(int n, int m){
        if(n == 1){
            return 0;
        }
        int x = f(n-1,m);
        return (x + m%n)%n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};
```