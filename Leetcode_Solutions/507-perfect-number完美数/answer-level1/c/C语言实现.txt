C语言实现
```C []
bool checkPerfectNumber(int num){
    if (0 == num || (num & 1)) return false;
    int i, sum = 1, sq = sqrt(num);
    for (i = 2; i < sq; ++i) if (num % i == 0) sum += i + num / i;
    if (num % sq == 0) sum += (num / sq == sq) ? sq : sq + num / sq;
    return sum == num;
}
```
