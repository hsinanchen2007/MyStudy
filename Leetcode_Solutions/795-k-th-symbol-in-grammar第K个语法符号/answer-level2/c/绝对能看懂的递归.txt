### 解题思路
无论第几行，第一个数是0，第二个数是1。
K为奇数时，第N行第K个数是第N - 1行的(K+1)/2个数的第1位（即N-1行第(K+1)/2个数是0的话为0，是1的话为1）
K为偶数时，第N行第K个数是第N - 1行的K/2个数的第2位（即N-1行第K+2个数是0的话为1，是1的话为0）
### 代码

```c
int kthGrammar(int N, int K) {
    if(K <= 0 || N <= 0){
        return 0;
    }
	if (K == 1) {
		return 0;
	}
	if (K == 2) {
		return 1;
	}
	if (K % 2 == 0) {
		if (kthGrammar(N - 1, K/2) == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (kthGrammar(N - 1, (K + 1)/2) == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
}
```