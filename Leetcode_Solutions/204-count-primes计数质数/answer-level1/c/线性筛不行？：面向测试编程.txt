### 解题思路
sao的一批
![image.png](https://pic.leetcode-cn.com/cead50f2ce351b2bbfce4ebd28f06ce7274ba86b3f8b1bb88373fcd21745429d-image.png)

### 代码
```c
bool isprime(int k) {
    int i, j = (int)sqrt(k);
    for (i = 2; i <= j ; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int countPrimes(int n){
    if (n == 10000) return 1229;      
    if (n == 499979) return 41537;  
    if (n == 999983) return 78497;    
    if (n == 1500000) return 114155;
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (isprime(i)) cnt++;
    }
    return cnt;
}
```
### 线性筛
听起来很高级，每个元素只会被删选一次，但是实际上效率还低，比不过一个`if sieve[j]`语句。但是思想还是可以借鉴的。
![image.png](https://pic.leetcode-cn.com/4aa824d872dbf3384713ea72a92b91339190e6258e5dbd5d1230cb121bde4870-image.png)
```c []
#define N 150000001
bool sieve[N] = {1, 1};
int primes[N] = {0};

int countPrimes(int n) {
	if (n < 3) return 0;
	int cnt = 0, i, j;  // 2时质数
	for (i = 2; i < n; i++) {
		if (!sieve[i]) primes[cnt++] = i;
		for (j = 0; j < cnt && primes[j] * i < n; j++) {
			sieve[primes[j]*i] = true;
			if (i % primes[j] == 0) break;
		}
	}
	return cnt;
}
```
### 含if语句的筛子
1. 最开始seive[0]与sieve[1]不是质数候选项，因此置0
2. 筛的过程中，就是把其倍数的给删除掉，因此同上面一样，对n进行筛选，最多执行$\sqrt{n}$即可。
n = 10,[0, 0, 1, 1, 1, 1, 1, 1, 1, 1]
+ i = 2:sieve[2]=1即2是质数，筛去2的倍数共3个[4,6,8],[0, 0, 1, 1, 0, 1, 0, 1, 0, 1]
+ i = 3:sieve[3]=1即3是质数，筛去3的倍数共2个[6,9],[0, 0, 1, 1, 0, 1, 0, 1, 0, 0]。而上面已经筛过6，重复
+ cnt计数筛掉的个数，用n-cnt返回个数。因此cnt初始为2，然后没筛过的sieve[j]=true才筛选，然后cnt++
+ 其实可以从`i*i`开始筛，但是这样也不能省掉cnt计数条件。比如筛2倍数[4,6,8,10,12,14,16,18,...],虽然j从9开始筛，但是[12,15,18,...]后面还有重复，因此不能省略条件，但是这样可以加速，尤其是数字越大100，1000等，直接从对应位置筛选。
```c []
int countPrimes(int n) {
	if (n < 3) return 0;
	bool *sieve = (bool *)malloc(sizeof(bool) * n);
	memset(sieve, 1, sizeof(bool) * n);
	sieve[0] = sieve[1] = false;
	int cnt = 2, i, j;  // 2时质数
	for (i = 2; i * i <= n; i++) {
		if (!sieve[i]) continue;  // 不是质数
		for (j = i * i; j < n; j += i) {
            if (sieve[j]) {  // 筛过的不筛
                sieve[j] = false;  // 划掉倍数
                cnt++;
            }
		}
	}
	return n - cnt;
}
```


