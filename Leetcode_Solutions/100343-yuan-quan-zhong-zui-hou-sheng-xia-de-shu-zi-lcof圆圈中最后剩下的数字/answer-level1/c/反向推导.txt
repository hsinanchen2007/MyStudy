### 反向推导法求尾数
已知n、m，求结尾数字x 
  解：原数列为0,1,2,...,n-1;
  x在原数列的下标是X0 = x+1 ; 
    第1次删除结点后，假设x的下标为X1,则有(X1 + m%n)%n = X0 - 1=X;
    第2次删除结点后，假设x的下标为X2,则有(X2 + m%(n-1))%(n-1) = X1;
    ....
   第n-1次删除结点后，整个数列只剩一个数，这个数也就是我们要求的尾数(值为x)，
   此刻它的下标一定为Xn-1 = 0，则有( Xn-2+m%(n-(n-2)) )%(n-(n-2)) = 0;
    (Xn-2+m%(2))%2 = 0; 
![image.png](https://pic.leetcode-cn.com/bce83119afbdc7cc76b8e012b13394e8bf44c6cc0d06be08a5a53c8e826ba0aa-image.png)


### 代码

```c
int lastRemaining(int n, int m){
	int last = 0;
	for(int i=2;i<=n;i++)
	{
		last = (last+m%i)%i;
	}
	return last;
}
```