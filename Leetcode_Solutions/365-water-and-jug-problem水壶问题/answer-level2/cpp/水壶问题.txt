### 解题思路
如果两个杯子的量不足z，肯定装不了
如果两个杯子和或者某一个杯子正好等于z，那就恰好装下
最后看一下，如果z能整除x与y的公约数也是能装下的。

### 代码

```cpp
class Solution {
public:
    int gcd(int x,int y){
        return y==0?x:gcd(y,x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (x+y<z)
            return false;
        if(x+y==z||x==z||y==z)
            return true;
        return z % gcd(x, y) == 0;
    }
};
```