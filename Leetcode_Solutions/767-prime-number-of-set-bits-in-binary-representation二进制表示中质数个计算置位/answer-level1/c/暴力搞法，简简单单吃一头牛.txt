```
int Calc(int num)
{
    int total = 0;

    while(num) {
        if (num % 2) {
            total++;
        }
        num /= 2;
    }
    return total;
}

bool Check(int num) {
    if (num < 2) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    for (int i = 2; i <= sqrt(num)/*num / 2*/; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimeSetBits(int L, int R)
{
    int res = 0;
    int num = 0;

    for (int i = L; i <= R; i++) {
        num = Calc(i);
        if (Check(num)) {
            res++;
        }
    }
    return res;
}
```
