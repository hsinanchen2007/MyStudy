### 解题思路
此处撰写解题思路

### 代码

```c
bool isPrime(int num)
{
    if (num == 1 || num == 0) {
        return false;
    }
    
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool process(int num)
{
    int bit_cnt = 0;

    while (num) {
        if (num % 2) {
            bit_cnt++;
        }

        num /= 2;
    }

    return isPrime(bit_cnt);
}

int countPrimeSetBits(int L, int R){
    int res_cnt = 0;

    for (int i = L; i <= R; i++) {
        if (process(i)) {
            res_cnt++;
        }
    }

    return res_cnt;
}
```