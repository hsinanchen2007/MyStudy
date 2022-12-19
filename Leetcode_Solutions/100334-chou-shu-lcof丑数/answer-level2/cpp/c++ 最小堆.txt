### 解题思路
用一个set做最小堆，先压入1，然后每次取出堆顶的值，乘上2、3、5后再压入堆。当取到第n次的时候就是结果。

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> sst;
        sst.emplace(1);
        int k = 1;
        while(k < n) {
            auto v = *sst.begin();
            sst.erase(v);
            sst.emplace(v*2);
            sst.emplace(v*3);
            sst.emplace(v*5);
            k++;
        }
        return *sst.begin();
    }
};
```