### 解题思路
两种思路。
第一，穷举法：
将大的水壶里的水一次次地倒进小水壶里，当小水壶倒满时，将小水壶里的水倒掉。反复操作，如果出现了所需要的数字，则输出true，如果出现了以前出现过的数字，则说明进入了循环，则返回false。

第二，求最大公约数法：
只要z小于x+y，则只要z可以被x和y的最大公约数cdiv整除，那么z必然可以被x和y倒出来。因为在0到x+y之间的所有能被cdiv整除的数都能够通过有限次倒水得出。

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x > y) // 确保x是较小的那个数，方便计算
            swap(x,y);
        if(z > y + x)
            return false;
        if(z == x || z == y || z == x + y)
            return true;
        if(!x) // 当x=0且z不等于x或y时，返回false
            return false;
        int cdiv = 1; // 最大公约数
        if(!(y % x) && (z % x))// 如果y可以被x整除，且z不可以被x整除，返回false
            return false;
        else if(!(y % x) && !(z % x)) // 如果y和z都可以被x整除，返回true（两种特殊情况）
            return true;
        for(int i = 2; i * i <= x; i++) // 求最大公约数
        {
            if(!(x % i))
            {
                if(!(y % i))
                    cdiv = i;
                if(!(y % (x / i)))
                {
                    cdiv = x / i;
                    break;
                }
            }
        }

        if(z % cdiv)
            return false;
        else
            return true;
    }
};
```