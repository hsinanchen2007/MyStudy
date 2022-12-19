### 解题思路
上代码

### 代码

```c
int gcd(int num1, int num2) {
    int mod = num1 % num2;
    if (mod == 0) {
        return num2;
    } else {
        return gcd(num2, mod);
    }
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) {
        return false;
    }
    if (x == 0 || y == 0) {
        return z == 0 || x + y == z;
    }
    return z % gcd(x, y) == 0;
}
```