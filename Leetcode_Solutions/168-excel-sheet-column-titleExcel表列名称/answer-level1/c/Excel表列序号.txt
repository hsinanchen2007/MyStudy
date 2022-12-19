### 解题思路
但是和一般的进制转换不太一样，这里A（不在末位时）和Z均可以表示26，如：在**AB**中`A=26`，而在**BZ**中的`Z=26`。这个26的倍数是一种特殊情况。

这个题很容易想到下面这种方法：
```c
while(n>0)
{
    ret[i++] = n % 26 + 'A' - 1;
    n /= 26;
}
```
当n为26的倍数时（如`n = 52`），上面的方法就行不通了，所以直接定义一个标志位，如果n为26的整数倍时，则将n-1，然后就可以按照上面的方法求解，最后根据标志位再将最后一位字符+1即可。

### 代码

```c
char * convertToTitle(int n){
    int N = 99;
    char *ret = (char*)malloc(sizeof(char) * N);
	memset(ret, 0, N);
	int i = 0;
	int temp = 0, flag = 0;
	while(n > 26)
	{
		temp = n % 26;
        if(temp == 0) // 当n为26的倍数时，将n-1
        {
            n--;
            flag = 1;
            continue;
        }
		ret[i++] = temp + 64;
		n /= 26;		
	}
	ret[i++] = n + 64;
    if(flag)
    {
        ret[0]++;
    }
    if(i == 1)
    {
        return ret;
    }
    int j = 0;
    // 字符串逆序
    while(j < i)
    {
        int temp = ret[j];
        ret[j] = ret[i-1];
        ret[i-1] = temp;
        j++;
        i--;
    }
	return ret;
}

```