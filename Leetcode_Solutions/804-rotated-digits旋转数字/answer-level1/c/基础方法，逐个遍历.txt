### 解题思路
1、好数需要符合条件：至少含有2、5、6、9中的一个，必须不含:3、4、7

### 代码

```c
int rotatedDigits(int N){
	if(N < 2)
	{
		return 0;
	}
	int i = 1;
	int ret = 0;
	for ( i = 2; i <= N; i++) 
	{
		int have2569 = 0; // 含有2、5、6、9的标志位
		int bad = 0; // 含有3、4、7的标志位
		int temp = i;
		while(temp > 0 && bad == 0)
		{
			switch(temp%10)
			{
				case 2:
				case 5:
				case 6:
				case 9:
					have2569 = 1;
					break;
				case 3:
				case 4:
				case 7:
					bad = 1;
					break;
			}
			temp /= 10;
		}
		if(bad == 0 && have2569 == 1)
		{
			ret++;
		}
	}
	return ret;

}
```