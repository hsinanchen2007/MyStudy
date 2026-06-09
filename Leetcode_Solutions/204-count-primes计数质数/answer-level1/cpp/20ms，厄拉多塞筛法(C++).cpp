执行用时 : 20 ms, 在Count Primes的C++提交中击败了98.62% 的用户

内存消耗 : 11.3 MB, 在Count Primes的C++提交中击败了34.66% 的用户


```c++[]
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
		return 0;
		
	bool *arr = (bool*)malloc(n*sizeof(bool));
        memset(arr, true , n*sizeof(bool));
		
	for (int i = 3; i <= sqrt(n); i += 2)
            if(arr[i])
                for (int j = i*i ; j < n; j += i) 
                        arr[j] = false;

	int res = 1;
	for (int i = 3; i < n; i += 2)
		if (arr[i])
			res++;
	return res;
    }
};
```
