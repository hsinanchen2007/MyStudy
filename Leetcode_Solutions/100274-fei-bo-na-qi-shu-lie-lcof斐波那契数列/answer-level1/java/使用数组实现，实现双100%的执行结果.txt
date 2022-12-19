直接使用递归来实现裴波那契数列，可能会出现超时的问题。这里使用一个数组来存储每个n对应的结果。
```
public int fib(int n) {
	int[] ans=new int[n+1];
	if(n==0) {
		return 0;
	}
	if(n==1) {
		return 1;
	}
	ans[0]=0;
	ans[1]=1;
	for(int i=2;i<=n;i++) {
		ans[i]=(ans[i-1]+ans[i-2])%1000000007;
	}
	return ans[n];
}
```
