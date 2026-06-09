### 解题思路
分析一下
- 不可能有两个壶同时处于不满不空的状态
- 装满只对空瓶操作，否则相当于之前操作作废
- 倒水不改变水的总量
- 装满操作是加法 
- 清空操作是减法
- 二者都以操作对象容量为运算对象 
- 操作次数相当于系数
- **运算结果为mx+ny**
- 验证一下对系数基本没有要求，运算结果只要在允许范围内都可以得到
代码实现
- mx+ny的取值是最大公因数的倍数
- 只要验证z是不是最大公因数的倍数就好了
第一次写出双一百的代码，纪念一下
![image.png](https://pic.leetcode-cn.com/39c7f1422ac74bc32bebd9d6adffc9ded26b327ccaa1e4131fbbc10b689ee5dd-image.png)

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z<0||z>x+y)
        return false;
        if(!z) return true;//边界
        int g;
        if(x==0||y==0)//除数不为0
            g=x+y;
        else
            g=gcd(x,y);
        return !(z%g);
    }
    int gcd(int a,int b)//辗转相除法
    {
        if(a%b==0)
            return b;
        return gcd(b,a%b);
    }

};
```