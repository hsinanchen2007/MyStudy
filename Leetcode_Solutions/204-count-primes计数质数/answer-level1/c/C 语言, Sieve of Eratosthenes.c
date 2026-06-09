### 解题思路

Sieve of Eratosthenes

### 代码

```c
int isPrimeNumber (int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    int n = sqrt(num);
    int i = 3;
    while (i <= n && num % i) i += 2;

    return i > n;
}

// int countPrimes(int n){
//     --n;
//     if (n <= 1) return 0;
//     if (n == 2) return 1;

//     n = n - (n % 2 == 0? 1: 0);
//     int cnt = 1;
//     for (int i = n; i > 2; i -= 2) {
//         if (isPrimeNumber(i)) ++cnt;
//     }

//     return cnt;
// }

int countPrimes(int n){
    if (n == 0 || n == 1) return 0;
    int nums[n];
    for (int i = 0; i < n; ++i) nums[i] = 1;
    nums[0] = nums[1] = 0;

    for (int i = 2; i * i < n; ++i) {
        if (nums[i]) {
            for (int j = i * i; j < n; j += i) nums[j] = 0;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (nums[i]) ++cnt;

    return cnt;
}
```