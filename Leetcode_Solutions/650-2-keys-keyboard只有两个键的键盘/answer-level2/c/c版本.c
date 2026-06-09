
```
int g_elem[1001] = {-1};

int minSteps(int n){

    memset(g_elem, 0, sizeof(g_elem));
    return minStepsRecur(n);
}

int minStepsRecur(int n)
{
    if (n == 1)
        return 0;

    if (g_elem[n] > 0)
        return g_elem[n];

    int end = n / 2;
    int i = 0;
    for (i = 2; i < end; i++)
    {
        if (n % i != 0)
            continue;

         g_elem[n] = minSteps(n / i) + i;
         return g_elem[n];
    }

    g_elem[n] = n;
    return n;
}
```
