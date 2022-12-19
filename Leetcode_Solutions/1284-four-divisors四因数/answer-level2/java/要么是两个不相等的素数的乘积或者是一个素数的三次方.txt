要么是两个不相等的素数的乘积或者是一个素数的三次方
先筛选一遍素数

```
public int sumFourDivisors(int[] nums) {
        int res = 0;
        boolean[] primes = new boolean[250000];
        Arrays.fill(primes, true);
        
        int b = (int) Math.sqrt(250000);
        for(int i = 2; i <= b; i++) {
            if (!primes[i]) {
                continue;
            }
            
            for(int j = i * i; j < 250000; j += i) {
                primes[j] = false;
            }
        }
        
        int len = 0;
        for(int i = 2; i < 250000; i++) {
            if (primes[i]) {
                len++;
            }
        }
        
        int[] arr = new int[len];
        int index = 0;
        for(int i = 2; i < 250000; i++) {
            if (primes[i]) {
                arr[index++] = i;
            }
        }
        
        for(int n : nums) {
            for(int i = 0; i < len; i++) {
                if (arr[i] * arr[i] > n) {
                    break;
                }
                
                if (n % arr[i] == 0) {
                    int p = n / arr[i];
                    if (p == arr[i]) {
                        continue;
                    }
                    
                    if (primes[p] || p == arr[i] * arr[i]) {
                        res += (1 + n + arr[i] + p);
                    }
                }
            }
        }
        
        return res;
    }
```
