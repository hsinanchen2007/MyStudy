```
int reverse(int x)
{
    long long target;
    long long ans = 0;

    target = x;
    if(target <= INT_MIN || target >= INT_MAX) return 0;
    while (target != 0)
    {
		ans = ans * 10 + target % 10;
		target = target / 10;
    }
    if(ans <= INT_MIN || ans >= INT_MAX) return 0;
    return ans;
}

```

