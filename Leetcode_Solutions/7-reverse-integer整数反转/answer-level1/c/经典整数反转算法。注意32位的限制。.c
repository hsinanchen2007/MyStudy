### 解题思路
此处撰写解题思路

### 代码

```c
int reverse(int x){
    int xx = x;
	int out_xx = 0;
	if (x < 0)
	{
        if ( x < ((int)pow(2 * 1.0, 31)-1) * (-1))
		{
			return 0;
		}
		xx = x * (-1);
	}
	
	while (xx > 0)
	{
		if (out_xx  > ((int)pow(2 * 1.0, 31) - 1)/10)
		{
			return 0;
		}
		out_xx *= 10;
		if (out_xx > ((int)pow(2 * 1.0, 31) - 1 - xx % 10))
		{
			return 0;
		}

		out_xx += xx % 10;
		xx /= 10;
	}

	if (x < 0)
	{
		out_xx *= -1;
	}
	
	return out_xx;

}
```