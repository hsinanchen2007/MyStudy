### 解题思路
此处撰写解题思路

### 代码

```c
int gcd(int a, int b)
{
    int r;
    if (a < b) {
        r = a;
        a = b;
        b = r;
    }
    r = a % b;
    while (r != 0) {
        a = r;
        r = b % r;
        b = a;
    }
    return b;
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) {
        return false;
    }
    if (z == 0) {
        return true;
    }
    if (x == 0 || y == 0) {
        if (x + y == z) {
            return true;
        }
        return false;
    }
    if (z % gcd(x, y) == 0) {
        return true;
    }
    return false;
}
```