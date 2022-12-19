![image.png](https://pic.leetcode-cn.com/898003fe5e48243e9216b01bf1738279fd8128428f2898ec03c54ed84cf7dc77-image.png)
### 解题思路
该题的结论: 若z不能整除x, y的最大公约数, 则一定不能; 否则一定能。
        即：若x,y最大公约数为1, 一定能装出1~max(x,y)体积的水; 题目还可以用两个容器装, 则可以装出1~x+y体积的水。
        若x,y的最大公约数大于1, 且z能整除该数, 则约分后也装换为上述情况。

PS: 结论都是手写了几个例子之后猜出来的ψ(*｀ー´)ψ


### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y) return false;
        int large = max(x,y);
        int small = min(x,y);
        while(small > 0) {
            large %= small;
            swap(large, small);
        }        
        if(large > 1 && z % large != 0)
            return false;
        return true;
    }
};
```