### 解题思路
最普通算法 不进位异或操作+进位与操作即实现。

### 代码

```c
int getSum(int a, int b)
{
	
	int sum=a;
	unsigned int carry=b;
	while(carry)
	{
		int temp=sum;
		sum=temp^carry;
		carry=(temp&carry)<<1;

	}
	return sum;
}




```