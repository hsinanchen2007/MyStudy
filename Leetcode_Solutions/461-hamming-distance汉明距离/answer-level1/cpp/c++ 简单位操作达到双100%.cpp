### 解题思路
对于计算机来讲，进行位操作的时间代价是最低的，因此很多程序往往可以通过位操作来进行的初级的性能优化。
本题即是这样的一个例子。
实现比较简单，直接看代码就好了。

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        bool fx, fy;
        while(!(x == 0 && y == 0)){
            fx = x & 1;
            fy = y & 1;
            x >>= 1;
            y >>= 1;
            distance += (fx != fy);
        }
        return distance;
    }
};
```