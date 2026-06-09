### 解题思路
1、先分正负零；
2、然后在res上倒着写入。
3、完成后根据正负判断首字符。

### 代码

```c
char * convertToBase7(int num){
	int sigh = 0;
	if (num < 0){
		sigh = 1;
		num = abs(num);
	}
	else if (num == 0)
		return "0";
//以上为第一步
	char *res = (char*)calloc(20, 1);
	res = &res[18];
	while (num){
		*res-- = num % 7 + 48;
		num /= 7;
	}
//以上为第二步
	if (sigh)
		*res = '-';
	else
		res++;
//第三步
	return res;
}
```