思路：
根据裴蜀定理，z能整除x和y的最大公约数的话就可以实现
*注意特殊情况处理：x=0,y=0；x+y<z等等
```
int gcd(int a,int b)
{
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a == b) {
        return a;
    }
    int mod = a % b;
    while (mod != 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}
bool canMeasureWater(int x, int y, int z){
    if (x == z || y == z || x + y == z) {
        return true;
    }
    if (gcd(x,y) == 0 || x + y < z) {
        return false;
    }
    return (z % gcd(x, y) == 0);
}
```
