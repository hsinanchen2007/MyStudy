### 解题思路
观察，只有2和3是特殊的，其余的都是分奇数偶数两种情况：
奇数n : temp = (n - 1) / 2;
a[n] = max(a[temp] * a[temp + 1], a[temp - 1] * a[temp + 2]);
偶数n : temp = k / 2;
a[n] = max(a[temp] * a[temp], a[temp - 1] * a[temp + 1]);

### 代码

```cpp
class Solution {
public:
long long a[59];

int integerBreak(int n)
{
    if (n == 2)
    {
        return 1;
    }
    if (n == 3)
    {
        return 2;
    }

    a[1] = 0;
    a[2] = 2;
    a[3] = 3;
    for (int k = 4; k <= 58; k++)
    {
        if (k % 2 == 0)
        {
            int temp = k / 2;
            a[k] = max(a[temp] * a[temp], a[temp - 1] * a[temp + 1]);
        }
        else
        {
            int temp = (k - 1) / 2;
            a[k] = max(a[temp] * a[temp + 1], a[temp - 1] * a[temp + 2]);
        }
    }
    return a[n];
}
};
```