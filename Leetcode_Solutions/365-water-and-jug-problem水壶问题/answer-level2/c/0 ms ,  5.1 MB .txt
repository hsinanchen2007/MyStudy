### 代码

```c
int gcd(int a, int b)
{
        int tmp;

        while (b > 0)
        {
                tmp = a % b;
                a = b;
                b = tmp;
        }
        return a;
}

bool canMeasureWater(int x, int y, int z)
{
        if (z == 0)
        {
                return true;
        }
        if (z > x + y)
        {
                return false;
        }

        return z % gcd(x, y) == 0 ? true : false;
}
```