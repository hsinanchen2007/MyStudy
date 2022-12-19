### 解题思路
本来是想找x与y能得到的最小容量（0除外），然后以这个为每次的增量就可以得到x与y所有的可能，结果昨晚对比了发现和官方的数学解法一样，然后还有个定理，我这算是歪打正着了吗哈哈哈哈

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if(x+y<z) return false; 
        int smaller = min(x,y);
        int bigger = max(x,y);
        while(smaller > 0)
        {
            int tmp = bigger - smaller;
            bigger = max(tmp,smaller);
            smaller = min(tmp,smaller) ;
        }
        return z%bigger == 0;
    }
};
```