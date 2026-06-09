### 解题思路
用一个辅助类的static变量来记录 sum，在构造函数中不断累加；不喜勿喷呦~~

### 代码

```cpp
class A{
public:
    A(){
        sum += (++num);
    }
public:
    static int num;
    static int sum;
};
int A::num = 0;
int A::sum = 0;


class Solution {
public:
    int sumNums(int n) {
        A::num = 0, A::sum = 0;
        A* p = new A[n];
        delete[] p;
        return A::sum;
    }
};
```