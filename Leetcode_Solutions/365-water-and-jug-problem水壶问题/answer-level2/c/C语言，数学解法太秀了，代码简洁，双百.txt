### 解题思路
![image.png](https://pic.leetcode-cn.com/6b8462cb4313a92fb0bfd76fbde3bd3675c3d8eaf0849ad46bacf6323663cb5a-image.png)
这道题的数学解法太秀了，简单说下我的理解：

首先，从两个水壶里的整体水量来看，每次操作，可分为下列情况：
1.往空壶里加满水，总量加x/y；
2.倒掉一壶水（满），总量减x/y；
3.倒掉一壶水（不满），总量变成x/y/0；
4.往不满的壶里加水，总量变为x/y/x+y；
5.从一个壶往另一个壶里倒水，总量不变；

所以，两个壶里水的总量一定是ax+by（a,b为整数），立即推，当z=ax+by时，返回true。

然后是贝祖定理：若x,y是整数,且gcd(x,y)=d，那么对于任意的整数a,b,ax+by都一定是d的倍数，特别地，一定存在整数a,b，使ax+by=d成立。

由贝祖定理可知，若存在整数a,b，使得ax+by=z成立，则z一定为x.y最大公因数的整数倍。

证明如下：

设x,y的最大公因数为d；
故存在整数i,j,使得x=i*d,y=j*d；
若ax+by=z成立，则
ax+by = a*(i*d)+b*(j*d) = (a*i+b*j)*d = z；
由此可得，z为d的整数倍。

所以，这道题就变成了判断z是否是x,y最大公因数的整数倍

### 代码

```c
int GCD(int a,int b){
    return a%b==0?b:GCD(b,a%b);
}

bool canMeasureWater(int x, int y, int z){
    if(x==0&&y==0) return z==0;
    if(z>x+y) return false;
    int a=y==0?GCD(y,x):GCD(x,y);
    return z%a==0;
}
```