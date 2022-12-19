递归，数组b控制列，数组a控制斜线方向
```
int sum=0;
int a[100],b[100],N;
void ss(int n) {
	if(n==N) {
		sum++;
		return ;
	}
	for(int i=0; i<N; i++) {
		if(b[i]==0) {
			int t=0;
			for(int j=0; j<n; j++)
				if(j+a[j]==n+i||j-a[j]==n-i) {
					t=1;
					break;
				}
			if(t==0) {
				a[n]=i;
				b[i]=1;
				ss(n+1);
				b[i]=0;
			}
		}
	}
}
int totalNQueens(int n) {
	for(int i=0; i<n; i++)
		b[i]=0;
	sum=0;
	N=n;
	ss(0);
	return sum;
}
```
