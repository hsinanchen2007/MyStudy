
![image.png](https://pic.leetcode-cn.com/f8791f7720a6e3d79ddf6133e917b989871744a5e093d41233e85f5beb8aa693-image.png)

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        return ((int)pow(n,2)+n)>>1;
    }
};
```