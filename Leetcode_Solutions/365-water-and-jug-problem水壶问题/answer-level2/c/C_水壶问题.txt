### 解题思路
数学思路最好用
### 代码

```c
//求最大公因数
int publicNum(int X,int Y)
{
    if(Y==0) return X;
    return publicNum(Y,X%Y);
}
//注意一下特殊xy返回特殊值
bool canMeasureWater(int x, int y, int z){
    if (x + y < z) return false;
    if (x == 0 || y == 0) return z == 0 || x + y == z;
    return z%publicNum(x,y)==0;
}
```