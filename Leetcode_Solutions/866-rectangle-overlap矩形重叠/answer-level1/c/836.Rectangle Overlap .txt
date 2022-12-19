### 解题思路
*记：1.Xl为左边的x，Xr为右边的x；2.Yh为上边的y，Ys为下边的y; 3.a,b为2个矩形* 
+ 1.当（aXl-bXr）乘（aXr-bXl）为负，且（aYh-bYs）乘（aYs-bYh）为负，有重合；
# 解题思路
*记：1.Xl为左边的x，Xr为右边的x；2.Yh为上边的y，Ys为下边的y; 3.a,b为2个矩形* 
+ 1.当（aXl-bXr）乘（aXr-bXl）为负，且（aYh-bYs）乘（aYs-bYh）为负，交集非空；
+ 2.单独考虑a与b边重合：若重合且交集非空，则乘积为负；而交集为空，则乘积为0。

此代码时间内存都是提交里最优的，但用了很多三元运算符，不易理解，以后应注重可读性

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
long long x1=rec1[0];
long long y1=rec1[1];
long long x2=rec1[2];
long long y2=rec1[3];
long long x3=rec2[0];
long long y3=rec2[1];
long long x4=rec2[2];
long long y4=rec2[3];
long long hor=((x1>x2?x1:x2)-(x3<x4?x3:x4))*((x1<x2?x1:x2)-(x3>x4?x3:x4));
long long ver=((y1>y2?y1:y2)-(y3<y4?y3:y4))*((y1<y2?y1:y2)-(y3>y4?y3:y4));
if(hor<0&&ver<0)
{
    return 1;
}
else
{
    return 0;
}
}
```