

![2020-03-21 21-15-59屏幕截图.png](https://pic.leetcode-cn.com/ab2907f73ebd5bf28d7454edc0039d34e812fca427f2b03fb11e19452a4a4fcb-2020-03-21%2021-15-59%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
// 最大公约数
int max(int a, int b)
{
    if (a == 0 || b == 0)
        return b + a;

    while(a != b){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

bool canMeasureWater(int x, int y, int z){

    if( x + y < z)
        return false;

    if(z == 0)
        return true;

    int n = max(x, y);

    if(z % n == 0)
        return true;

    return false;
}
```
