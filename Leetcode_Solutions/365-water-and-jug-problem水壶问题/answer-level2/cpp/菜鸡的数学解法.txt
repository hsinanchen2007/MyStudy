### 解题思路
微妙的数学解法
先把一堆奇怪的情况特判掉，剩下的就是需要用数学算的情况（看着贼蠢的一堆if主要是我太垃圾了不会优雅一点的写法……官方题解的就很妙
根据数论里的结论 如果两个数的最大公约数为d 那么其他d的倍数都可以用这两个数构造出来
所以直接求一下公倍数 看看z是不是这个公倍数的倍数

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0)
            return 1;
        if(x==0&&y==0&&z!=0)
            return 0;
        if((x<=0&&z%y!=0)||(y<=0&&z%x!=0))
            return 0;
        if((x<=0&&z%y==0)||(y<=0&&z%x==0))
            return 1;
        if(z>x+y)
            return 0;
        int minn=min(x,y),g;
        bool ans=1;
        return z%gcd(x,y)==0;
        //return ans;
    }
};
```