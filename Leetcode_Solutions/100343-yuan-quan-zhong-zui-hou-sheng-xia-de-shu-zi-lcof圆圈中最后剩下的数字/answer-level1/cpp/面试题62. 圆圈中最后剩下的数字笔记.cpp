### 解题思路
此处撰写解题思路
1. C++ vector容器解析：https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
2. vector<bool> flag(n, true) 初始化一个vector，长度为n，所有值都为true
3. 这题的解题思路为 求f(n,m)，则先走m%n步，然后求x=f(n-1,m), 则f(n,m)=(m%n+x)%n=(m+x)%n,如果想不明白，可以用具体的例子套一下
### 代码

```cpp
class Solution {
public:
    int f(int n, int m) {
        if (n == 1) return 0;
        int x = f(n - 1, m);
        
        return (x + m) % n;
    }

    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};
```