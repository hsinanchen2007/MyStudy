### 暴力求每一位数字
求每一位数字，然后乘以权重

### 代码

```c
int reverse(int x){
    int weishu = 0;
    long result = 0;
    int shuju = x;

    while(x)
    {
        weishu++;
        x = x/10;
    }


    for(int i = weishu; i > 0; i--)
    {
        result += (shuju%10)*pow(10,(i-1));
        shuju = shuju/10;
    }

	if((result > (pow(2,31)-1))||(result < (-pow(2,31))))
	{
		result = 0;
	}

    return (int)(result);
}
```