### 解题思路
数学方法，往壶里加水相当于加上x或y，把壶的水倒了相当于减去x或y

### 代码

```c
int gcd(int x, int y){
    int z;
    for(z = x % y;z != 0;y = z, z = x % y);
    return y;
}

bool canMeasureWater(int x, int y, int z){
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }
    if(x + y < z)
        return 0;
    if(x == 0 || y == 0)
        return z == 0 || x + y == z;
    else
        return z % gcd(x, y) == 0;
}
```