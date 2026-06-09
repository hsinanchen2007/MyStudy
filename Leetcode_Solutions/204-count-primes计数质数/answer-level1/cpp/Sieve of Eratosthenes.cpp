### 解题思路
执行用时 :28 ms, 在所有 C++ 提交中击败了94.68% 的用户
内存消耗 :11.3 MB, 在所有 C++ 提交中击败了24.10%的用户

### 代码

```cpp
class Solution {
public:
	bool isPrime(int val){
		for(int i=2;i<val;++i){
			if(!(val % i)) return false;
		}
		return true;
	}
	int countPrimes(int n){
		if(!n || (n == 1)) return 0;
		if(n == 3) return 1;
		int num_primes = 0;

		bool* is_prime_record = new bool[n];
		for(int i=0;i<n;++i) is_prime_record[i] = true;

		for(int i=2; i*i<n; ++i){
			if(isPrime(i)){
				for(int j=i*i; j<n; j+=i){
					is_prime_record[j] = false;
				}
			}
		}
		for(int i=2;i<n;++i){
			if(is_prime_record[i]) num_primes++;
		}

		return num_primes;
	}
};
```