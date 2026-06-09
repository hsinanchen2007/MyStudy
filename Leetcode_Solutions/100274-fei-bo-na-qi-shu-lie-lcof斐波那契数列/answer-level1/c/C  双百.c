### 解题思路
此处撰写解题思路

### 代码

```c
int fib(int n){
	if(n==0 || n==1)	return n;
    int* a = (int*)malloc(sizeof(int)*(n+1));
	a[0] = 0;
	a[1] = 1;
	for(int i = 2;i<=n;i++)
		a[i] = (a[i-1] + a[i-2])%1000000007;
		
	return a[n];
}


```