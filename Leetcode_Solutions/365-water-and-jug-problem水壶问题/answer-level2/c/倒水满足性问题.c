### 解题思路
数学思想，wdnmd
由题意，总水量是ax+by 关键是是否能找到使这个总水量，最终剩余Z
而值的正负也看做 倒入和 倒出
有个裴蜀定理 发现若能使等式成立，那么在。必然使是两桶量的 最大公因数的整数倍
然后就写出来了
### 代码

```c
int GCD(int a,int b){
    return a%b==0? b : GCD(b,a%b);   //辗转相除法递归实现
}
bool canMeasureWater(int x, int y, int z){
    if(x==0||y==0)  return (z==x||z==y);
    if(z>x+y)       return false;
    int divisor=GCD(x,y);
    return z%divisor==0;

}
