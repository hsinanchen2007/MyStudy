tmp = (tmp << 1) + tmp;  表示剩以3

```
bool isPowerOfThree(int n){
    if (n < 1) return false;
    unsigned int tmp = 1;
    while (tmp < n) tmp = (tmp << 1) + tmp;
    return (tmp == n ? true : false);
}
```
