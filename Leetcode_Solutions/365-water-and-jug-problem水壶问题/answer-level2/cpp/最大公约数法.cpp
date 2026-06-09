### 解题思路
因为这题，我学会了求最大公约数：辗转相除法，我现在知道了辗转相除法的原因了
至于裴蜀定理为：
z=mx+ny要使之成立，就要是z%gcd(x,y)==0成立


### 代码

```cpp
        int gcd(int x,int y){
            if(x==0||y==0)
                return 0;
            int min=x<y?x:y;
            int max=x>=y?x:y;
            if(max%min==0)
                return min;
            else
                return gcd(min,max%min);
        }
//这里是辗转相除法：求gcd(x,y)
//两者间 大的为max，小的为min
/*
max= a min+b;  
求两者间的最大公约数，就要保证 max，min和b要被这个最大公约数除尽，
因此问题转换为求b和min之间的公约数 
最后终会得到 min%b==0


那么如何求最小公倍数呢？

最小公倍数=两数乘积/最大公约数

最小公倍数=（因子1*最大公约数）*（因子2*最大公约数）/最大公约数

*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        //裴蜀定理
        //Z=mX+nY,其中，Z一定是X和Y的最大公约数的倍数 即Z%(mX+nY)==0

        //此题就是为了解决 Z是否可以表示为mX+nY的形式，
        //系数为正表示舀进，系数为负表示舀出

        //所以为题沦为 z是否为x,y的最大公约数的整数倍
        if((x==0&&y==0&&z!=0))//只有一个为0
            return false;
        if(x==0&&y!=0&&z!=0)//x为0，y不为0
            return z%y==0?true:false;
        if(y==0&&x!=0&&z!=0)//x不为0，y为0
            return z%x==0?true:false;
        if(x+y<z)
            return false;

        if(z==0||z%gcd(x,y)==0)
            return true;
        else    
            return false;

    }
};
```