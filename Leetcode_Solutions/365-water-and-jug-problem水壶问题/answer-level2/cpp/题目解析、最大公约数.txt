### 解题思路
 // 首先，为什么这个题目是转换成 x*n + y*m = z
            // 看题目的意思是 把x、y加满或清空（+或-）若干次后 == z
            // 那么x经过x1次满水和x2次清空的意思就是： x1-X2 = n
            // 所以n不是把x加满n次或者清空n次
        // 然后问题就变成了 x*n + y*m = z 是否有根的问题了
            // 有个数学定理： gcd（x,y）= k ==》 那么存在 n，m 使得 x*n + y*m = k
            // 当然 k == z肯定可以，但是不仅如此 等式两边同乘一个整数肯定也成立
            // 所以 z是k的倍数即可： z%k == 0
 // 另外 连个壶装不下肯定是false了

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {

       

        if (z == 0)
            return true;

        if (x == 0 || y == 0)
            return false;

       
        if (z > x+y )
            return false;

        int gcd = __gcd(x, y);
        if (z%gcd == 0)
            return true;
        else
            return false;
    }

};
```