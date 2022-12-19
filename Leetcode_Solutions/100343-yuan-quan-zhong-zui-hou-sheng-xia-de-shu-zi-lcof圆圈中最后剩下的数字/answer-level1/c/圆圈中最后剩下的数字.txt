### 解题思路
约瑟夫环地推公式法
### 代码

```c
int lastRemaining(int n, int m){
    int res=0;
	for(int i=2;i<=n;i++)
	{
		res=(res+m)%i;
	}
	return res;
}
```